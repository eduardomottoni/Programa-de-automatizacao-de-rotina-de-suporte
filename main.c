#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(){
	int i,ping,lojaputty,pdvputty,pingpdv,pingpdv2,loja,numpdvs,pdv,serv,pdvtotal,z,tempo;
	int alterar;
	int loja1, loja2;
	char command[150],intermed[100],intermed2[150],decisao[3];
	system("del cmd\\pinggeral.bat");
	system("del cmd\\pingespecifico.bat");
	system("del cmd\\pingpdvs.bat");
	system("del comandos\\comandoespecial.txt");
    system("echo #Insira o comando e salve>comandos\\comandoespecial.txt");
    system("del comandos\\comandoespecialserv.txt");
	system("echo #Insira o comando e salve>comandos\\comandoespecialserv.txt");
	system("del comandos\\comandoespecialpdvtotal.txt");
	system("echo #Insira o comando e salve>comandos\\comandoespecialpdvtotal.txt");
	system("del comandos\\lojaservpostgrespc.txt");
	
	

	Sleep(100);
	system("cls");
	for (;;){
	int num;
	system("cls");
	printf("V4.5.1\n"); ///alterar a cada versão **********
	printf("AUTO\n1.Resetar som\n2.Reiniciar pdv\n3.Coletor Offline(sigma-mobile/postgremsql)\n4.Sigma/Softlog OFF\n5.Caixas offline\n6.Vendas nao sobem\n7.Servidor 200 fora do ar\n16.Pingar loja\n17.Pingar maquina\n18.Pingar todos os pdvs da loja\n\nABRIR PUTTY\n8.Acessar pdv via Putty\n9.Acessar servidor 100 LOJA\n10.Acessar servidor 200 LOJA como usuario suporte\n\n\nVNC\n22.Acessar TightVNC\n23.Reiniciar vncserver e abrir TightVNC\n\n\n100.\"COMANDOS ESPECIAIS\"\n99.Encerrar\n");
	printf("\nEntre com um numero:\n");
	scanf("%d",&num);
	
	if (num>=22&&num<=25){
			printf("Digite o numero da loja(ex:10):\n");
			scanf("%d",&lojaputty);
			snprintf (intermed, sizeof(intermed), "echo %d>vnc\\loja.txt", lojaputty);
			system(intermed);
			printf("Digite a maquina a ser acessada ex:(101)\n");
			scanf("%d",&pdvputty);
			snprintf (intermed, sizeof(intermed), "echo %d>vnc\\pdv.txt", pdvputty);
			system(intermed);
		}else if (num>0&&num<=15&&num!=4){ //Os numeros estão reservados até o 40
		
		printf("Digite o numero da loja(ex:\"3\", \"9\", \"20\"):\n");
		scanf("%d",&lojaputty);
		
		if (num<=15||num>30){
		snprintf (intermed, sizeof(intermed), "echo \"%d\">putty\\loja.txt", lojaputty);
		system(intermed);}}
		
		else if(num>15&&num<20){
		printf("Digite o numero da loja(ex:10):\n");
		scanf("%d",&lojaputty);
		snprintf (intermed, sizeof(intermed), "echo \"%d\">cmd\\loja.txt", lojaputty);
		system(intermed);
		}
		if (num==17){
			printf("Digite a maquina a ser pingada ex:(101)\n");
			scanf("%d",&pdvputty);
			snprintf (intermed, sizeof(intermed), "echo \"%d\">cmd\\pdv.txt", pdvputty);
			system(intermed);
		}
		
	if (num==2||num==8){
		printf("Digite o numero do pdv(ex:102)):\n");
		scanf("%d",&pdvputty);
		snprintf (intermed, sizeof(intermed), "echo \"%d\">putty\\pdv.txt", pdvputty); //script especial para 2 e 8
		system(intermed);

	}
	
	switch (num){
		case 1:
			strcpy( command, "start putty\\Resetsom.vbs" );
		    system(command);
		    break;

		case 2:
			printf("Atencao, voce esta prestes a reiniciar um PDV, verifique se o mesmo nao esta em uso.\n");
			system("pause");
			strcpy( command, "start putty\\RebootPDV.vbs" );
		    system(command);
		    break;

		case 9:
		    strcpy( command, "start putty\\Acessoservidor100.vbs" );
		    system(command);
		    break;
		/*case 4:
		    strcpy( command, "start putty\\Acessoservidor200.bat" );
		    system(command);
		    break;*/
		case 8:
		    strcpy( command, "start putty\\AcessoPDV.vbs" );
		    system(command);
		    break;
		case 3:
		    strcpy( command, "start putty\\Resetpostgresqlsigmamobile.vbs" );
		    system(command);
		    break;
		case 4:
			memset (&decisao, 0, sizeof(decisao));
		    strcpy( command, "start putty\\Softlog.vbs" );
		    system(command);
		    printf("\nDeseja Tambem reiniciar a Maquina Virtual?\nsim/nao\n");
		    scanf("%s",&decisao);
		    if (strcmp(decisao,"sim")==0||strcmp(decisao,"s")==0||strcmp(decisao,"Sim")==0||strcmp(decisao,"S")==0){
		    printf("feche o programa caso mude de ideia");
		    system("pause");
		    strcpy( command, "start putty\\Softlogreboot.vbs" );
		    system(command);	
			}
		    break;
		case 6:
			strcpy( command, "start putty\\vendassub.vbs" );
		    system(command);
		    break;
		    //case 10:
		    //strcpy( command, "start putty\\Acessoservidor100arius.bat" );
		    //system(command);
		    //break;
		case 7:
			strcpy(command, "start putty\\servidor200fora.vbs" );
		    system(command);
		    break;
		
		case 10:
		    strcpy( command, "start putty\\Acessoservidor200.vbs" );
		    system(command);
		    break;
			
		case 16:
			printf("Digite o numero de pdvs a serem pingados (ex:5 = pinga ate o 105))\n");
			scanf("%d",&pingpdv2);
			system("del cmd\\pinggeral.bat");
			system("cls");
			system("start cmd\\Pingadministrador.bat");
			Sleep(300);
			for(ping=1;ping<=pingpdv2;ping++){
			if(ping<10){snprintf (intermed, sizeof(intermed), "echo ping 10.10.%d.10%d -n 3 -l 70 >>cmd\\pinggeral.bat",lojaputty, ping); // o arquivo que armazena a lista de comandos ping é o pinggeral
			system(intermed);}
			else{snprintf (intermed, sizeof(intermed), "echo ping 10.10.%d.1%d -n 3 -l 70 >>cmd\\pinggeral.bat",lojaputty, ping);//porém, isso não funcionou bem, foi melhor adicionar as 3 ultimas linhas do Pingadministrador a este código e poder acrescentar tantos comandos quantos necessários nesse comando
			system(intermed);
			}}
			system ("echo pause >> cmd\\pinggeral.bat");
			system ("echo exit >> cmd\\pinggeral.bat");
			system ("start cmd\\pinggeral.bat");
 		    break;
		case 17:
			system("@del cmd\\pingespecifico.bat");
			strcpy(command,"@start cmd\\Pingpdvadm.bat" );
		    system(command);
		    break;
		case 18:
			printf("Digite o numero de pdvs a serem pingados (ex:5 = pinga ate o 105))\n");
			scanf("%d",&pingpdv2);
			system("del cmd\\pingpdvs.bat");
			for(ping=1;ping<=pingpdv2;ping++){
			if(ping<10){snprintf (intermed, sizeof(intermed), "echo ping 10.10.%d.10%d -n 3 -l 150 >>cmd\\pingpdvs.bat",lojaputty, ping);
			system(intermed);}
			else{snprintf (intermed, sizeof(intermed), "echo ping 10.10.%d.1%d -n 3 -l 150 >>cmd\\pingpdvs.bat",lojaputty, ping);
			system(intermed);
			}}
			system("echo pause >>cmd\\pingpdvs.bat");
			system("echo exit >>cmd\\pingpdvs.bat");
			system("start cmd\\pingpdvs.bat");
			break;
		case 22:
		    strcpy( command, "start vnc\\VNC.vbs" );
		    system(command);
		    break;
		case 5:
		    strcpy( command, "start putty\\caixasoff.vbs" );
		    system(command);
		    break;
		case 201:
		    strcpy( command, "start putty\\Resetsom200.vbs" );
		    system(command);
		    break;
		case 202:
			strcpy( command, "start putty\\Resetpostgresqlsigmamobile200.vbs" );
		    system(command);
		    break;
		case 23:
			strcpy( command, "start vnc\\vncserverrestart.vbs" );
		    system(command);
		    printf("\nEspere o fechamento da janela plink\n");
		    system("pause");
		    strcpy( command, "start vnc\\vncserverrestart2.vbs" );
		    system(command);
		    break;
		case 40:
		    strcpy( command, "start putty\\Acessoservidor200arius.vbs" );
		    system(command);
		    break;
		
		case 50:
            printf("Digite a loja: \n");
		    scanf("%d",&loja);
			pdv = 101;
            printf("Digite o numero de pdvs: \n");
		    scanf("%d",&numpdvs);
		    printf("Digite o tempo entre imputs (1000 = 1 segundo;use pelo menos 200))\n");
            scanf("%d",&tempo);
			
            //itoa(loja,intermed,10);
            snprintf (intermed, sizeof(intermed), "echo \"%d\"> comandos\\loja.txt", loja);
		    system(intermed);
		    system("start comandos\\comandoespecial.txt");
		    system("pause");
		    printf("\nAguarde...");
            for (i=1; i<=numpdvs;i++){
            if(i<10){strcpy(intermed,"");
            strcpy(intermed2,"echo ");
            //itoa(pdv,intermed,10);
            snprintf (intermed, sizeof (intermed), "echo 10%d", pdv);
            strcat(intermed,"> comandos\\pdv.txt");
            system("del comandos\\pdv.txt");
            //strcat (intermed2,">comandos\\pdv.txt");
            system(intermed);
            strcpy (command, "start scriptsespeciais\\comandosdiversos.vbs");
            system(command);
            pdv=pdv+1;}
            else{
            	strcpy(intermed,"");
            strcpy(intermed2,"echo ");
            //itoa(pdv,intermed,10);
            snprintf (intermed, sizeof (intermed), "echo 1%d", pdv);
            strcat(intermed,"> comandos\\pdv.txt");
            system("del comandos\\pdv.txt");
            //strcat (intermed2,">comandos\\pdv.txt");
            system(intermed);
            strcpy (command, "start scriptsespeciais\\comandosdiversos.vbs");
            system(command);
            pdv=pdv+1;
			}
            Sleep(250);
            Sleep(tempo);
            }system("del comandos\\comandoespecial.txt");
            system("echo #Insira o comando e salve>comandos\\comandoespecial.txt");
			break;

            case 60:
            printf("Digite o servidor(100,200)\n");
            scanf("%d",&serv);
            if (serv!=100&&serv!=200){printf("comando invalido");
			Sleep(2000);
			break;
			}
            printf("Digite o tempo entre imputs (1000 = 1 segundo;use pelo menos 200))\n");
            scanf("%d",&tempo);
            snprintf (intermed, sizeof (intermed), "echo %d> comandos\\serv.txt", serv);
		    system(intermed);
            printf("digite o intervalo de lojas ex(5 30)");
            scanf("%d %d",&loja1,&loja2);
		    system("start comandos\\comandoespecialserv.txt");
            system("pause");
            printf("\nAguarde...");
            for (i=loja1; i<=loja2;i++){
            loja1=i;
            snprintf (intermed, sizeof (intermed), "echo \"%d\"> comandos\\lojaserv2.txt", loja1);
		    system(intermed);
		    if (serv==100){
            strcpy (command, "start scriptsespeciais\\comandosdiversosserv.vbs");
            system(command);
            Sleep(tempo);}else if(serv==200){
            strcpy (command, "start scriptsespeciais\\comandosdiversosserv200.vbs");
            system(command);
            Sleep(250);
			Sleep(tempo);}else{break;}
            }
			system("del comandos\\comandoespecialserv.txt");
			system("echo #Insira o comando e salve>comandos\\comandoespecialserv.txt");
			break;
		
			case 70:
			printf("Digite o numero de pdvs (ex 15)\n");
            scanf("%d",&pdvtotal);
            printf("Digite o tempo entre imputs (1000 = 1 segundo;use pelo menos 200))\n");
            scanf("%d",&tempo);
            printf("Digite o intervalo de lojas(ex 1 15)\n");
            scanf("%d %d",&loja1,&loja2);
		    system("start comandos\\comandoespecialpdvtotal.txt");
            system("pause");
            printf("\nAguarde...");
            for (i=loja1;i<=loja2;i++){
			snprintf (intermed, sizeof (intermed), "echo \"%d\"> comandos\\lojatodosospdvs.txt", i);
            system(intermed);
            for(z=1;z<=pdvtotal;z++){
            if (z<10){
			snprintf (intermed, sizeof (intermed), "echo \"10%d\"> comandos\\numpdvtodos.txt", z);
            system(intermed);
            system("start scriptsespeciais\\comandopdvtotal.vbs");
			Sleep(tempo);	
			}else{
			snprintf (intermed, sizeof (intermed), "echo \"1%d\"> comandos\\numpdvtodos.txt", z);
            system(intermed);
            system("start scriptsespeciais\\comandopdvtotal.vbs");
			Sleep(250);
			Sleep(tempo);	
			}
        	}}
			system("del comandos\\comandoespecialpdvtotal.txt");
			system("echo #Insira o comando e salve>comandos\\comandoespecialpdvtotal.txt");
			break;
					
			case 100:
			system("start comandosespeciais.txt");
			break;
				
		case 99:
			return 0;
			
		default:
			printf("comando invalido");
			Sleep(500);
			break;
			}}}
