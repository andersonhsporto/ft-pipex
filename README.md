# Pipex
![norminette](https://github.com/andersonhsporto/ft-pipex/workflows/norminette/badge.svg)
### O objetivo deste projeto é reproduzir o comportamento de  redirecionamento <br> utilizando pipe " | " em C.
<hr>
## Funções Permitidas



As funções permitidas no escopo deste projeto são:
```
• access
• open
• unlink
• close
• read
• write
• malloc
• waitpid
• wait
• free
• pipe
• dup
• dup2
• execve
• fork
• perror
• strerror
• exit
```
O programa simula o comportamento do seguinte comando no “shell”: (cmd1 e cmd2 são comandos do “shell” e suas respectivas flags).
```sh
< arquivo_input cmd1 | cmd2 > arquivo_output
```
Compile o programa utilizando **make**, o programa deve ser executado da seguinte forma:
```sh
./pipex arquivo_input "cmd1" "cmd2" arquivo_output
```

##



## REFERÊNCIAS
* Informação Adicional - [Pipe](https://www.ppgia.pucpr.br/pt/arquivos/techdocs/linux/foca-iniciante/ch-redir.html)