#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int diasnomes(int mes, int ano){
	int cont = 0;
	for(int i = 0; i < mes; i++){
    if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
        cont += 31;
    }
    else if (i == 4 || i == 6 || i == 9 || i == 11) {
        cont += 30;
    }
    else if (i == 2) {
        if (ano % 4 == 0) {
            cont += 29;
        }
        else cont += 28;
    }
	}
    return cont;
}

int diasnoano(int ano){
	int cont = 0;
	for(int i = 0; i < ano; i++){
	    if (i % 4 == 0){
        cont += 366;
        
    }else cont += 365;
	}
	return cont;
	}

int compdata(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
	fflush(stdin);
	int a = dia1 + diasnoano(ano1 - 1) + diasnomes(mes1 - 1, ano1);
	int b = dia2 + diasnoano(ano2 - 1) + diasnomes(mes2 - 1, ano2);
	if (a >= b){
		return 1;
	}else return 0;
}

struct hotel{
	int situacao;
	int diain, mesin, anoin, diaout, mesout, anoout;
	int ndehospedes;
	char nomehospedes[3][30];
	char emailhospedet[30];
	char telefonehospedet[30];
	char nomefuncionario[30];
	};
struct data{
	int dia, mes, ano;
};
int main(){
	SetConsoleOutputCP(65001);
	char nomefuncionario [40];
	int qdesejado, ndehospedesdesejado;
	int checkoutautomatico = 0;
	int algumquartoocupado = 0;
	struct data hoje;
	struct data in;
	struct data out;
	struct hotel q[30];
		for (int i = 1; i < 31; i++){
			q[i].situacao = 0;
			q[i].ndehospedes = 0;
			}	
	while(1){
	int opcao = 1;
	int opcao2 = 0;
	int quartocorreto = 0;
	int datacorreta = 0;
	int numerodehospedescorreto = 0;
	printf("Qual o seu nome?\n");
	fflush(stdin);
	scanf(" %[^\n]", nomefuncionario);
	fflush(stdin);
	printf("Qual o dia, mês e ano da data de hoje?\n");
	scanf("%d %d %d", & hoje.dia, & hoje.mes, & hoje.ano);
							
	if(algumquartoocupado != 0){
		for (int i = 1; i < 31; i++){
			if(q[i].situacao == 1){
		if(compdata(hoje.dia, hoje.mes, hoje.ano, q[i].diaout + 1, q[i].mesout, q[i].anoout) == 1){
		q[i].situacao = 0;
		q[i].ndehospedes = 0;
		printf("O quarto %d foi esvaziado\n", i);
		algumquartoocupado -= 1;
		}
	}}}
	
		while(opcao != 3){
		printf("\nDigite 1 para ver a lista quartos disponíveis\nDigite 2 para ver as reservas efetuadas\nDigite 3 para efetuar uma reserva\nDigite 4 para cancelar uma reserva\n");
		scanf("%d", & opcao);
		if (opcao == 1){
			printf("Quartos disponíveis:\n");
			for (int i = 1; i < 31; i++){
				if (q[i].situacao == 0){
					printf("%d  ", i);
				}
			}
			printf("\n\n");
		}
		else if (opcao == 2){
			printf("Reservas efetuadas:");
			for (int i = 1; i < 31; i++){
				if (q[i].situacao == 1){
				printf("\nQuarto %d:\n", i);
				printf("Data de check-in da reserva: %d/%d/%d\n", q[i].diain, q[i].mesin, q[i].anoin);
				printf("Data de check-out da reserva: %d/%d/%d\n", q[i].diaout, q[i].mesout, q[i].anoout);
				printf("Número de hóspedes: %d\n", q[i].ndehospedes);
				printf("Nome do hóspede titular: %s\n", q[i].nomehospedes[0]);
				printf("Email do hóspede titular: %s\n", q[i].emailhospedet);
				printf("Telefone do hóspede titular: %s\n", q[i].telefonehospedet);
				printf("Nome do funcionário que efetuou a reserva: %s\n", q[i].nomefuncionario);
		}}
			if (algumquartoocupado == 0){
			printf(" Nenhuma\n");
		}}
		else if (opcao == 4){
			if(algumquartoocupado != 0){
				printf("Quarto(s) ocupado(s):\n");
				for (int i = 1; i < 31; i++){
				if (q[i].situacao == 1){
					printf("%d  ", i);}}
					printf("\nDigite o número do quarto que você quer cancelar a reserva, ou outro número inteiro que não seja um quarto válido para voltar para as opções iniciais\n");
					scanf(" %d", & opcao2);
					if(opcao2 > 0 && opcao2 < 31){
						q[opcao2].situacao = 0;
						q[opcao2].ndehospedes = 0;
						printf("O quarto %d foi esvaziado", opcao2);
						algumquartoocupado -= 1;
					}
					}
				else{
					printf("Nenhum quarto ocupado\n");}
			}}
		while(quartocorreto == 0){
		printf("\nDigite o número do quarto que você deseja reservar\n");
		scanf("%d", & qdesejado);
			if (q[qdesejado].situacao == 1){
				printf("Este quarto está ocupado\n");
			}else if (qdesejado <= 0 || qdesejado >=31){
				printf("Este quarto não existe\n");
			}else{
				quartocorreto = 1;
				q[qdesejado].situacao = 1;}}

				while(datacorreta == 0){
				printf("\nDigite o dia, mês e ano da data de chek-in\n");
				scanf("%d %d %d", & in.dia, & in.mes, & in.ano);
				if(compdata(in.dia, in.mes, in.ano, hoje.dia, hoje.mes, hoje.ano) == 0){
				printf("Você digitou uma data inválida\n");
				}else {
					q[qdesejado].diain = in.dia; q[qdesejado].mesin = in.mes; q[qdesejado].anoin = in.ano;
					datacorreta = 1;
			}}
			datacorreta = 0;
				while(datacorreta == 0){
				printf("\nDigite o dia, mês e ano da data de chek-out\n");
				scanf("%d %d %d", & out.dia, & out.mes, & out.ano);
				if(compdata(out.dia, out.mes, out.ano, in.dia, in.mes, in.ano) == 0){
				printf("Você digitou uma data inválida\n");
				}else {
				q[qdesejado].diaout = out.dia; q[qdesejado].mesout = out.mes; q[qdesejado].anoout = out.ano;
				datacorreta = 1;
			}}
				while(numerodehospedescorreto == 0){
				printf("\nDigite o número de hóspedes\n");
				scanf("%d", & ndehospedesdesejado);
				if (ndehospedesdesejado > 0 && ndehospedesdesejado < 5){
					q[qdesejado].ndehospedes = ndehospedesdesejado;
					numerodehospedescorreto = 1;}
					else{
						printf("\nO quarto não suporta o número de hóspedes digitado.\n");	
					}}
					
				printf("\nDigite o nome do hóspede titular\n");
				fflush(stdin);
				scanf(" %[^\n]", & q[qdesejado].nomehospedes[0]);
				printf("\nDigite o email do hóspede titular\n");
				scanf(" %s", & q[qdesejado].emailhospedet);
				printf("\nDigite o telefone do hóspede titular\n");
				scanf(" %s", & q[qdesejado].telefonehospedet);
				if (q[qdesejado].ndehospedes > 1){
					for(int i = 1; i < q[qdesejado].ndehospedes; i++){
				printf("\nDigite o nome do %dº hóspede\n", i+1);
				fflush(stdin);
				scanf(" %[^\n]", & q[qdesejado].nomehospedes[i]);
					}
				}
				strcpy( q[qdesejado].nomefuncionario, nomefuncionario);
				algumquartoocupado += 1;
				system("cls");
				printf("Reserva efetuada\n\n");
				}
			}