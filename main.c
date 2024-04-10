       

      #include "ArrayList.h"

      // constantes
      enum {
          OP_NAO_SELECIONADA = 0,
          OP_ADD,
          OP_SAIR,
          OP_PRINT,
          OP_PRINTALL,
          OP_DELETE
      };

      // protótipos
      int op_menu();

      int main() {
          int opcao = OP_NAO_SELECIONADA;
          struct listV novoCliente; 
          int aux;
          init();

          while(opcao != OP_SAIR)
          {
              opcao = op_menu();
              switch (opcao) {
                  case OP_ADD:
                      
                      printf("Digite o nome do cliente: ");
                      scanf("%s", novoCliente.name);
                      printf("Digite o endereco do cliente: ");
                      scanf("%s", novoCliente.endereco);
                      printf("Digite o CPF do cliente: ");
                      scanf("%lf", &novoCliente.cpf);
                      printf("Digite o telefone do cliente: ");
                      scanf("%s", novoCliente.telefone);
                      printf("Digite o email do cliente: ");
                      scanf("%s", novoCliente.email);
                      add(novoCliente); 
                      break;
                  case OP_PRINTALL:
                    printAll();
                      break;
                  case OP_PRINT:
                      printf("Digite o CPF do cliente: ");
                      scanf("%d", &aux);   
                      print(aux);
                        break;
                  case OP_DELETE:
                      printf("Digite o CPF do cliente: ");
                      scanf("%d", &aux);
                      del(aux);
                      break;
                case OP_SAIR:
                      break;
                  default:
                      printf("Opcao invalida!\n");
                      break;
              }
          }
          destroy();
          return EXIT_SUCCESS;
      }

      int op_menu()
      {
          int op = OP_NAO_SELECIONADA;
          printf("MENU\n");
          printf("%d - Add\n", OP_ADD);
          printf("%d - Sair\n", OP_SAIR);
          printf("%d - Print\n", OP_PRINT);
          printf("%d - PrintAll\n", OP_PRINTALL);
          printf("%d - Delete\n", OP_DELETE);
          printf("Digite sua opcao: ");
          scanf("%d", &op);
          return op;
      }
