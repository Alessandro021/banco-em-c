#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int menu, cont = 0, auxCpf, auxCpf1, achou = 0, i, submenu, j, saque, depositar, limiteNovo, transferir, auxTrans = 0, a;
	float limiteInicial[10];
	float saldoInicial[10];
	char nome[10][15];
	int cpf[10];
	int agencia[10];
	int conta[10];

	do
	{
		printf("\n\tMenu principal\n");
		printf("\n\t1 - Cadastrar Conta");
		printf("\n\t2 - Acessar uma conta especifica");
		printf("\n\t3 - Sair");
		printf("\n\tDigite: ");
		scanf("%d", &menu);

		if (menu < 1 || menu > 3)
		{
			printf("\n\tOpcao invalida!\n");
		}
		else if (menu == 1 || menu == 2)
		{
			if (menu == 1)
			{
				printf("\n\tCPF: ");
				scanf("%d", &auxCpf);

				for (j = 0; j < 10; j++)
				{
					saldoInicial[j] = 200;
					limiteInicial[j] = 1000;
				}
				if (cont == 0)
				{
					cpf[cont] = auxCpf;
					setbuf(stdin, NULL);
					printf("\tNome: ");
					setbuf(stdin, NULL);
					scanf("%s", &nome[cont]);
					printf("\tConta: ");
					scanf("%d", &conta[cont]);
					printf("\tAgencia: ");
					scanf("%d", &agencia[cont]);
					printf("\n\tConta cadastrada com sucesso! \n");
					cont++;
				}
				else
				{
					achou = 0;
					if (cont < 10)
					{
						for (i = 0; i < cont; i++)
						{
							if (auxCpf == cpf[i])
							{
								printf("\n\tCPF ja cadastrado!\n");
								achou = 1;
							}
						}
					}
					if (achou == 0)
					{
						cpf[cont] = auxCpf;
						printf("\n\tNome: ");
						scanf("%s", &nome[cont]);
						printf("\n\tConta: ");
						scanf("%d", &conta[cont]);
						printf("\n\tAgencia: ");
						scanf("%d", &agencia[cont]);
						cont++;
					}
				}
			}
			if (menu == 2)
			{
				printf("\n\tInsira seu CPF: ");
				scanf("%d", &auxCpf);
				for (i = 0; i < cont; i++)
				{
					if (cpf[i] == auxCpf)
					{
						int pos = 0;
						pos = i;
						do
						{
							printf("Escolha a operacao: \n");
							printf("\n\t1 - Sacar");
							printf("\n\t2 - Depositar");
							printf("\n\t3 - Transferir");
							printf("\n\t4 - Alterar limite");
							printf("\n\t5 - Sair\n");
							printf("\n\tDigite: ");
							scanf("%d", &submenu);

							if (submenu < 1 || submenu > 5)
							{
								printf("\n\tOpcao invalida\n");
							}
							else if (submenu == 1 || submenu == 2 || submenu == 3 || submenu == 4)
							{
								if (submenu == 1)
								{
									printf("\n\tInforme o valor para o saque: ");
									scanf("%d", &saque);
									if (saldoInicial[j] > saque)
									{
										saldoInicial[j] = saldoInicial[j] - saque;
										printf("\n\tSaldo atual  de: %.1f", saldoInicial[j]);
									}
									else
									{
										printf("\n\tNao possui saldo suficiente para o saque");
									}
								}
								if (submenu == 2)
								{
									printf("\n\tInforme o valor para o deposito: ");
									scanf("%d", &depositar);
									saldoInicial[j] = saldoInicial[j] + depositar;
									printf("\n\tSaldo atual: %.1f\n", saldoInicial[j]);
								}
								if (submenu == 3)
								{
									printf("\n\tInforme para qual CPF deseja realizar a transferencia: ");
									scanf("%d", &auxCpf1);
									for (i = 0; i < cont; i++)
									{
										if ((cpf[i] == auxCpf1) && (auxCpf != auxCpf1))
										{
											printf("\n\tInforme o valor para a transferencia: ");
											scanf("%d", &transferir);
											if (saldoInicial[pos] > transferir)
											{
												saldoInicial[i] = saldoInicial[i] - transferir;
												saldoInicial[pos] = saldoInicial[pos] + transferir;
												printf("\n\tSaldo atual: %.1f", saldoInicial[i]);
											}
											else
											{
												printf("\n\tSaldo insuficiente para realizar transferencia");
											}
										}
									}
								}
								if (submenu == 4)
								{
									printf("\n\tInforme o novo limite: ");
									scanf("%d", &limiteNovo);
									limiteInicial[j] = limiteNovo;
									printf("\n\tSeu novo limite e :  %.1f\n", limiteInicial[j]);
								}
							}
						} while (submenu != 5);
					}
					else
					{
						printf("\n\tCPF nao cadastrado! Faca seu cadastro\n");
					}
				}
			}
		}

	} while (menu != 3);
}

