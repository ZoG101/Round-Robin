#include "Servico.h"
#include "CircularQueue.h"

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    std::unique_ptr<CircularQueue> CQ = std::make_unique<CircularQueue>();

    CQ->push(std::make_unique<Servico>(0));
    CQ->push(std::make_unique<Servico>(1));
    CQ->push(std::make_unique<Servico>(2));
    CQ->push(std::make_unique<Servico>(3));
    CQ->push(std::make_unique<Servico>(4));
    CQ->push(std::make_unique<Servico>(5));

    while (CQ->hasNext()) {};

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Processos finalizados com sucesso.\n";
    return 0;
}