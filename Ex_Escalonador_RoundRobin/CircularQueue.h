#pragma once
#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED

#include <vector>
#include <stdexcept>

#include "Servico.h"

class CircularQueue {
	private:
		std::vector<std::unique_ptr<Servico>>* caminhoes;
		int exec_;

		void pop(int pos) {
			if (this->isEmpty()) throw std::out_of_range("Fila vazia!");

			std::cout << "[Servico " << this->caminhoes->at(pos).get()->getId() << "] Encerrado com contador em: " << this->caminhoes->at(pos).get()->getContador() << "\n\n";

			this->caminhoes->at(pos).release();
			this->caminhoes->erase(this->caminhoes->begin() + pos);

			this->caminhoes->shrink_to_fit();
		};

	public:
		CircularQueue() {
			this->caminhoes = new std::vector<std::unique_ptr<Servico>>();
			this->exec_ = 0;
		}

		bool isEmpty() { return this->caminhoes->empty(); };

		int size() { return this->caminhoes->size(); };

		int first() { return this->caminhoes->at(this->exec_).get()->getId(); };

		void push(std::unique_ptr<Servico> s) { this->caminhoes->push_back(std::move(s)); };

		bool hasNext() {
			if (this->isEmpty()) return false;

			std::cout << "Processo: " << this->caminhoes->at(this->exec_).get()->getId() << "\n";

			if (this->caminhoes->at(this->exec_).get()->isStopped()) {
				this->caminhoes->at(this->exec_).get()->retomar();
				std::this_thread::sleep_for(std::chrono::seconds(2));
			} else {
				this->caminhoes->at(this->exec_).get()->iniciar();
				std::this_thread::sleep_for(std::chrono::seconds(2));
			}

			if (this->caminhoes->at(this->exec_).get()->getContador() >= 8) {
				this->caminhoes->at(this->exec_).get()->parar();
				this->pop(this->exec_);
			} else {
				this->caminhoes->at(this->exec_).get()->pausar();
				this->exec_ = (this->exec_ + 1) % this->size();
			}

			return true;
		}
};

#endif // !CIRCULARQUEUE_H_INCLUDED

