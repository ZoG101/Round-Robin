<section>
    <h1 align="center">Exemplo de Escalonador Round-Robin</h1>
    <blockquote cite="https://deinfo.uepg.br/~alunoso/2016/ROUNDROBIN/#:~:text=Escalonamento%20circular%20(Round%2DRobin),Jos%C3%A9%20Renato%20Soares%20Nunes%2C%201990.">
        <p>
            "É o tipo de escalonamento preemptivo mais simples e 
            consiste em repartir uniformemente o tempo da CPU 
            entre todos os processos prontos para a execução. 
            Os processos são organizados numa fila circular, 
            alocando-se a cada um uma fatia de tempo da CPU, 
            igual a um número inteiro de quanta. Caso um processo 
            não termine dentro de sua fatia de tempo, ele é colocado 
            no fim da fila e uma nova fatia de tempo é alocada para 
            o processo no começo da fila."
        </p>
        <p><cite>-Fonte: <a href="https://deinfo.uepg.br/~alunoso/2016/ROUNDROBIN/#:~:text=Escalonamento%20circular%20(Round%2DRobin),Jos%C3%A9%20Renato%20Soares%20Nunes%2C%201990.">Juliano & Gabriela</a></cite></p>
    </blockquote>
</section>
<section>
    <h2 align="center">Ideia da Atividade</h2>
    <p>
        A ideia é de um escalonador que executa um processo de 
        carregamento de caminhões em forma de serviço. Cada serviço deve 
        ser executado na seguinte ordem: 
    </p>
    <ul>
        <li>Empacotar</li>
        <li>Carregar</li>
        <li>Fechar</li>
        <li>Sair</li>
    </ul>
    <p>
        Cada serviço tem dois segundos de execução por vez e, 
        caso o serviço tenha finalizado, ele é retirado da fila. 
        Caso ainda tenha algo para ser executado, ele passa para o 
        fim da fila e aguarda a próxima oportunidade de finalizar a tarefa.
    </p>
</section>
<section>
    <h2 align="center">Tecnologias Utilizadas</h2>
    <div align="left">
        <img width="30" />
        <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="30" alt="cplusplus logo"  />
    </div>
</section>
