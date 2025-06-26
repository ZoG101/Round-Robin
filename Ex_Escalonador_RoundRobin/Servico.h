#pragma once
#ifndef SERVICO_H_INCLUDED
#define SERVICO_H_INCLUDED

#include <iostream>
#include <thread>
#include <chrono>
#include <stop_token>
#include <condition_variable>
#include <mutex>

class Servico {
    private:
        int id_;
        int contador_;
        bool pausado_;
        std::jthread thread_;
        std::mutex mtx_;
        std::condition_variable cv_;

    public:
        Servico(int id) : id_(id), contador_(0), pausado_(false) {}

        void iniciar() {
            this->thread_ = std::jthread([this](std::stop_token st) {
                while (!st.stop_requested()) {
                    std::unique_lock<std::mutex> lock(this->mtx_);
                    this->cv_.wait(lock, [&] { return !this->pausado_ || st.stop_requested(); });

                    if (st.stop_requested()) break;

                    switch (this->contador_)
                    {
                    case 0:
                        std::cout << "[Servico " << this->id_ << "] Empacotando... " << "\n";
                        break;
                    case 1:
                        std::cout << "[Servico " << this->id_ << "] Empacotando... " << "\n";
                        break;
                    case 2:
                        std::cout << "[Servico " << this->id_ << "] Carregando... " << "\n";
                        break;
                    case 3:
                        std::cout << "[Servico " << this->id_ << "] Carregando... " << "\n";
                        break;
                    case 4:
                        std::cout << "[Servico " << this->id_ << "] Fechando... " << "\n";
                        break;
                    case 5:
                        std::cout << "[Servico " << this->id_ << "] Saindo... " << "\n";
                        break;
                    default:
                        std::cout << "[Servico " << this->id_ << "] Finalizado... " << "\n";
                        break;
                    };

                    this->contador_ = this->contador_ + 1;
                    std::cout << "\n";
                    
                    lock.unlock();
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
            });
        }

        void pausar() {
            std::lock_guard<std::mutex> lock(this->mtx_);
            this->pausado_ = true;
        }

        void retomar() {
            {
                std::lock_guard<std::mutex> lock(this->mtx_);
                this->pausado_ = false;
            }
            this->cv_.notify_one();
        }

        void parar() {
            this->thread_.request_stop();
            this->cv_.notify_one();
        }

        int getId() { return this->id_; };

        int getContador() { return this->contador_; };

        bool isStopped() { return this->pausado_; };
};

#endif // !SERVICO_H_INCLUDED

