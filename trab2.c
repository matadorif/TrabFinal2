#include <stdio.h>	
#include <stdlib.h> 
#include <string.h>

int main(){
		
	srand(time(NULL));
	int op;
	
	for(;;){
		
		printf("---------------------------------------\n");
		printf("\tMENU DE IMAGENS\n");
		printf("--------------------------------------- \n\n");
		printf("1 - Converter p/ escala de cinza \n");
		printf("2 - Espelhar horizontalmente \n");
		printf("3 - Espelhar verticalmente \n");
		printf("4 - Dividir verticalmente \n");
		printf("5 - Dividir horizontalmente \n");
		printf("6 - Colorir aleatoriamente \n");
		printf("7 - Rotacionar 90 graus p/ direita \n");
		printf("8 - Rotacionar 90 graus p/ esquerda \n");	
		printf("9 - Sair\n\n");
		printf("Digite o que deseja fazer: ");
		scanf("%d", &op);
			
		switch(op){
				
			case 1:{
				FILE *arq;
				FILE *forward;
				arq = fopen("imagem.ppm", "r");
				forward = fopen("imagem_cinza.ppm", "w");
				
				char buffer[100];
	
				int r, g, b, media;
				
				if(arq != NULL){
					fgets(buffer, 100, arq);
					fgets(buffer, 100, arq);
					fgets(buffer, 100, arq);
					fgets(buffer, 100, arq);
					
					fprintf(forward, "P2\n");
					fprintf(forward, "#IMAGEM CINZA\n");
					fprintf(forward, "400 400\n");
					fprintf(forward, "255\n");
					while(fscanf(arq, "%d\n%d\n%d\n", &r, &g, &b) != EOF){
						media = (r + g + b) / 3;
						fprintf(forward, "%d\n", media);
					}
				}
			
				fclose(arq);
				fclose(forward);
				
				printf("\nConvertida com sucesso!");
				printf("\n\n");
							
				break;
			}
			
				
			case 2:{
				FILE *arq;	
				FILE *forward;
				arq = fopen("imagem.ppm", "r");
				forward = fopen("imagem_espelhada_horizontal.ppm", "w");
				
				char buffer[100];
			
				int l, h, max;
				
				fgets(buffer, 100, arq);
				fgets(buffer, 100, arq);
				
				fscanf(arq, "%d", &l); 
				fscanf(arq, "%d", &h);
				fscanf(arq, "%d", &max);	
				
				int m[h][l][3];
				int i, j, k;
				for(i = 0; i < l; i++){
					for(j = 0; j < h; j++){
						for(k = 0; k < 3; k++){
							fscanf(arq, "%d", &m[i][j][k]);	
						}
					}
				}
			
				fprintf(forward, "P3\n");
				fprintf(forward, "#IMAGEM ESPELHADA HORIZONTALMENTE\n");
				fprintf(forward, "%d %d\n", l, h);
				fprintf(forward, "%d\n", max);
				
				h = h - 1;
				for(i = 0; i < l; i++){
					for(j = h; j >= 0; j--){
						for(k = 0; k < 3; k++){
							fprintf(forward, "%d\n", m[i][j][k]);
						}
					}
				}
				
				printf("\nEspelhada com sucesso!");
				printf("\n\n");
				
				fclose(arq);
				fclose(forward);
			
				break;
			}
					
				
			case 3:{
				FILE *arq;
				FILE *forward;
				arq = fopen("imagem.ppm", "r");
				forward = fopen("imagem_espelhada_vertical.ppm", "w");
				
				char buffer[100];
				
				int l, h, max;
				
				fgets(buffer, 100, arq);
				fgets(buffer, 100, arq);	
				
				fscanf(arq, "%d", &l);
				fscanf(arq, "%d", &h);
				fscanf(arq, "%d", &max);	
				
				int m[h][l][3];
				int i, j, k;
				
				for(i = 0; i < l; i++){
					for(j = 0; j < h; j++){
						for(k = 0; k < 3; k++){
							fscanf(arq, "%d", &m[i][j][k]);	
						}
					}
				}
				
				fprintf(forward, "P3\n");
				fprintf(forward, "#IMAGEM ESPELHADA VERTICALMENTE\n");
				fprintf(forward, "%d %d\n", l, h);
				fprintf(forward, "%d\n", max);
				
				l = l - 1;
				for(i = l; i >= 0; i--){
					for(j = 0; j < h; j++){
						for(k = 0; k < 3; k++){
							fprintf(forward, "%d\n", m[i][j][k]);
						}
					}
				}
				
				printf("\nEspelhada com sucesso!");
				printf("\n\n");
				
				fclose(arq);
				fclose(forward);
				
				break;
			}
					
			case 4:{
				FILE *arq;
				arq = fopen("imagem.ppm", "r");
				
				char buffer[100];
				
				int l, h, max;
				
				if(arq != NULL){
					fgets(buffer, 100, arq);
					fgets(buffer, 100, arq);
					
					fscanf(arq, "%d", &l);
					fscanf(arq, "%d", &h);
					fscanf(arq, "%d", &max);
					
					int m[h][l][3];
					int i, j, k;
					for(i = 0; i < l; i++){
						for(j = 0; j < h; j++){
							for(k = 0; k < 3; k++){
								fscanf(arq, "%d", &m[i][j][k]);	
							}
						}
					}
					
					l = 200;
					
					FILE *forward;
					
					forward = fopen("imagem_divisao_vertical1.ppm", "w");
					
					fprintf(forward, "P3\n");
					fprintf(forward, "#IMAGEM DIVIDIDA VERTICALMENTE 1\n");
					fprintf(forward, "%d %d\n", l, h);
					fprintf(forward, "%d\n", max);
					
					for(i = 0; i < 400; i++){
						for(j = 0; j < 200; j++){
							for(k = 0; k < 3; k++){
								fprintf(forward, "%d\n", m[i][j][k]);
							}
						}
					}
					
					FILE *forward2;
					
					forward2 = fopen("imagem_divisao_vertical2.ppm", "w");
					
					fprintf(forward2, "P3\n");
					fprintf(forward2, "#IMAGEM DIVIDIDA VERTICALMENTE 2\n");
					fprintf(forward2, "%d %d\n", l, h);
					fprintf(forward2, "%d\n", max);
					
					for(i = 0; i < 400; i++){
						for(j = 200; j < 400; j++){
							for(k = 0; k < 3; k++){
								fprintf(forward2, "%d\n", m[i][j][k]);
							}
						}
					}
					
					fclose(forward);
					fclose(forward2);
				}	
				
				printf("\nImagem dividida com sucesso!");
				printf("\n\n");
						
				fclose(arq);
				
				break;
			}
						
			case 5:{
				
				FILE *arq;
				arq = fopen("imagem.ppm", "r");
				
				char buffer[100];
				
				int l, h, max;
				
				if(arq != NULL){
					fgets(buffer, 100, arq);
					fgets(buffer, 100, arq);
					
					fscanf(arq, "%d", &l); 
					fscanf(arq, "%d", &h);
					fscanf(arq, "%d", &max);	
					
					int m[h][l][3];
					int i, j, k;
					
					for(i = 0; i < l; i++){
						for(j = 0; j < h; j++){
							for(k = 0; k < 3; k++){
								fscanf(arq, "%d", &m[i][j][k]);
							}
						}
					}
				
					h = 200;
					
					FILE *forward;
					forward = fopen("imagem_divisao_horizontal1.ppm", "w");
					
					fprintf(forward, "P3\n");
					fprintf(forward, "#IMAGEM DIVIDIDA HORIZONTALMENTE 1\n");
					fprintf(forward, "%d %d\n", l, h);
					fprintf(forward, "%d\n", max);
						
					for(i = 0; i < 200; i++){
						for(j = 0; j < 400; j++){
							for(k = 0; k < 3; k++){
								fprintf(forward, "%d\n", m[i][j][k]);
							}
						}
					}
					
					FILE *forward2;
					forward2 = fopen("imagem_divisao_horizontal2.ppm", "w");
					
					fprintf(forward2, "P3\n");
					fprintf(forward2, "#IMAGEM DIVIDIDA HORIZONTALMENTE 2\n");
					fprintf(forward2, "%d %d\n", l, h);
					fprintf(forward2, "%d\n", max);
					
					for(i = 200; i < l; i++){
						for(j = 0; j < 400; j++){
							for(k = 0; k < 3; k++){
								fprintf(forward2, "%d\n", m[i][j][k]);
							}
						}
					}
				
				fclose(forward);
				fclose(forward2);
				
				}	
			
				printf("\nImagem dividida com sucesso!");
				printf("\n\n");
				
				fclose(arq);
				
					
				break;
			}
						
				
			case 6:{
				FILE *arq;
				FILE *forward;
				arq = fopen("imagem_cinza.ppm", "r");
				forward = fopen("imagem_colorida.ppm", "w");
				
				char buffer[100];
				int corand[4][3];
				int r, g, b, pix, i, j;
				
				for(i = 0; i < 4; i++){
					for(j = 0; j < 3; j++){
						corand[i][j] = rand() % 255;
					}
				}
					
				fgets(buffer, 100, arq);
				fgets(buffer, 100, arq);
				fgets(buffer, 100, arq);
				fgets(buffer, 100, arq);
			
				fprintf(forward, "P3\n");
				fprintf(forward, "#IMAGEM COLORIDA ALEATORIAMENTE\n");
				fprintf(forward, "400 400\n");
				fprintf(forward, "255\n");
				
				while(fscanf(arq, "%d", &pix) != EOF) {
					if(pix < 64){
						fprintf(forward, "%d\n%d\n%d\n", corand[0][0], corand[0][1], corand[0][2]);
					}else if(pix < 128){
						fprintf(forward, "%d\n%d\n%d\n", corand[1][0], corand[1][1], corand[1][2]);
					}else if(pix < 192){
						fprintf(forward, "%d\n%d\n%d\n", corand[2][0], corand[2][1], corand[2][2]);
					}else {
						fprintf(forward, "%d\n%d\n%d\n", corand[3][0], corand[3][1], corand[3][2]);
					}	
				}
			
				printf("\nImagem colorida com sucesso!");
				printf("\n\n");
				
				fclose(arq); 
				fclose(forward);
				
				break;
			}
							
			case 7:{
				FILE *arq;
				FILE *forward;
				arq = fopen("imagem.ppm", "r");
				forward = fopen("imagem_90_direita.ppm", "w");
				
				char buffer[100];
				
				int l, h, max;
				
				fgets(buffer, 100, arq);
				fgets(buffer, 100, arq);
					
				fscanf(arq, "%d", &l);
				fscanf(arq, "%d", &h);
				fscanf(arq, "%d", &max);	
				
				int m[h][l][3];
				int i, j, k;
				
				for(i = 0; i < l; i++){
					for(j = 0; j < h; j++){
						for(k = 0; k < 3; k++){
							fscanf(arq, "%d", &m[i][j][k]);	
						}
					}
				}
				
				fprintf(forward, "P3\n");
				fprintf(forward, "#IMAGEM 90 GRAUS DIREITA\n");
				fprintf(forward, "%d %d\n", l, h);
				fprintf(forward, "%d\n", max);
				
				l = l - 1;
				
				for(i = l; i >= 0; i--){
					for(j = 0; j < h; j++){
						for(k = 0; k < 3; k++){
							fprintf(forward, "%d\n", m[j][i][k]);
						}
					}
				}
				
				printf("\nImagem rotacionada com sucesso!");
				printf("\n\n");
				
				fclose(arq);
				fclose(forward);
				
				break;
			}
							
				
			case 8:{
				FILE *arq;
				FILE *forward;
				arq = fopen("imagem.ppm", "r");
				forward = fopen("imagem_90_esquerda.ppm", "w");
				
				char buffer[100];
				
				int l, h, max;
				
				fgets(buffer, 100, arq);
				fgets(buffer, 100, arq);	
				
				fscanf(arq, "%d", &l);
				fscanf(arq, "%d", &h);
				fscanf(arq, "%d", &max);	
				
				int m[h][l][3];
				int i, j, k;
				
				for(i = 0; i < l; i++){
					for(j = 0; j < h; j++){
						for(k = 0; k < 3; k++){
							fscanf(arq, "%d", &m[i][j][k]);	
						}
					}
				}
				
				fprintf(forward, "P3\n");
				fprintf(forward, "#IMAGEM 90 GRAUS ESQUERDA\n");
				fprintf(forward, "%d %d\n", l, h);
				fprintf(forward, "%d\n", max);
				
				h = h - 1;
				
				for(i = 0; i < l; i++){
					for(j = h; j >= 0; j--){
						for(k = 0; k < 3; k++){
							fprintf(forward, "%d\n", m[j][i][k]);
						}
					}
				}
				
				printf("\nImagem rotacionada com sucesso!");
				printf("\n\n");
				
				fclose(arq);
				fclose(forward);
				
				break;
			}
					
			case 9:
				printf("\nObrigado pela visita!");
				return 1;
			break;
			
		}
		
		system("\n\n");
		system("pause");
		system("cls");
		
		
	}
	
}
