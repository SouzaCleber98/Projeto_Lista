       

      #include "ArrayList.h"

      // constantes
      enum {
          OP_NAO_SELECIONADA = 0,
          OP_ADD,
          OP_SAIR
      };

      // protótipos
      int menu();

      int main() {
          int opcao = OP_NAO_SELECIONADA;
          struct listV novoCliente; 

          init();

          while(opcao != OP_SAIR)
          {
              opcao = menu();
              switch (opcao) {
                  case OP_ADD:
                      
                      printf("Digite o nome do cliente: ");
                      scanf("%s", novoCliente.name);
                      printf("Digite o endereco do cliente: ");
                      scanf("%s", novoCliente.endereco);
                      printf("Digite o CPF do cliente: ");
                      scanf("%s", novoCliente.cpf);
                      printf("Digite o telefone do cliente: ");
                      scanf("%s", novoCliente.telefone);
                      printf("Digite o email do cliente: ");
                      scanf("%s", novoCliente.email);
                      add(novoCliente); 
                      break;
              }
          }
          destroy();
          return EXIT_SUCCESS;
      }

      int menu()
      {
          int op = OP_NAO_SELECIONADA;
          printf("MENU\n");
          printf("%d - Add\n", OP_ADD);
          printf("%d - Sair\n", OP_SAIR);
          printf("Digite sua opcao: ");
          scanf("%d", &op);
          return op;
      }
