#include <stdio.h>
int main(void) {

	printf("Hit and Blow (4桁) 解析ツール Ver1.0 へようこそ\n");

	char opt[10][10][10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {

					if (i != j && j != k && i != k && i != l && j != l && k != l) {
						//各位の値が全て異なる5040通りを格納

						opt[i][j][k][l] = 't';
						//optの値がtならば可能性としてありえる
					}

					else {
						opt[i][j][k][l] = 'f';
						//optの値がfならば可能性としてありえない
					}
				}
			}
		}
	}

	int count = 0;

	do{
		char numc[5];

		if (count > 0) {
			printf("\n");
		}

		printf("\n解析する値を入力してください：");
		scanf("%s", numc);
		//numc配列に解析値を格納

		if (numc[0] == 'e') {
			break;
		}

		int numcc[4] = { numc[0] - '0', numc[1] - '0',numc[2] - '0',numc[3] - '0' };
		//文字コードを数字コードに変換
		//解析する数値はnumcc配列[4]にint型で格納される

		int hit, blow;

		printf("hit数を入力してください：");
		scanf("%d", &hit);

		if (hit == 4) {
			printf("Win!\n");
			break;
		}

		printf("blow数を入力してください：");
		scanf("%d", &blow);

		//これと一致しないHit,Blow数を除外するため

		int hitc = 0;
		int blowc = 0;
		//ループ内で使用するカウント


		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					for (int l = 0; l < 10; l++) {

						if (opt[i][j][k][l] == 't') {

							//printf("%d %d %d %d", numcc[0], numcc[1], numcc[2], numcc[3]);
							//OK
							
							int num[4] = { i ,j ,k ,l };
							//num[4]配列にそれぞれ予測する値を格納(全探）
							//プレイモードで相手が決めている数の役割をnum[4]配列がうけもつ

							//printf("%d %d %d %d\n", num[0], num[1], num[2], num[3]);
							//OK

							hitc = 0;
							blowc = 0;
							//Hitc,Blowcのカウントをループ毎にリセット

							for (int m = 0; m < 4; m++) {

								if (num[m] == numcc[m]) {
									hitc++;
								}
								//位の数字が一致すればhitcに+1

								else {

									for (int n = 0; n < 4; n++) {

										if (m != n) {
											if (num[m] == numcc[n]) {
												blowc++;
											}
											//位の数字が一致せず、他の位と数字が一致したらblowcに+1
										}
									}
								}

							}//hitc,blowc数をカウント

							//printf("%d %d\n", hitc, blowc);


							if (hit == hitc && blow == blowc) {
								continue;
							}
							//一致したら書き換えずに現在のループをスキップ

							opt[i][j][k][l] = 'f';
							//Hit,Blow数が同一にならなければopt[i][j][k][l]に'f'を代入

						}
					}
				}
			}
		}

		printf("\n以下が考えられうる数です\n\n");

		int count20 = 0;
		//出力の改行用カウント

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					for (int l = 0; l < 10; l++) {

						if (opt[i][j][k][l] == 't') {

							int output = i * 1000 + j * 100 + k * 10 + l;
							printf("%04d ", output);
							//optの値が't'であるものを全て出力

							count20++;

							if (count20 == 20) {
								printf("\n");
								count20 = 0;
							}
						}
					}
				}
			}
		}

		count++;

	}while (count < 100);
	//解析回数が100回に達したらプログラムを終了する

	system("pause");
	
	return 0;
}