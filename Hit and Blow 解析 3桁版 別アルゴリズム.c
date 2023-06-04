#include <stdio.h>
int main(void) {

	printf("Hit and Blow (3桁) 解析ツール Ver2.0 へようこそ\n");

	char opt[10][10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {

					if (i != j && j != k && i != k ) {
						//各位の値が全て異なる720通りを格納

						opt[i][j][k]= 't';
						//optの値がtならば可能性としてありえる
					}

					else {
						opt[i][j][k]= 'f';
						//optの値がfならば可能性としてありえない
					}
			}
		}
	}

	int count = 0;

	do {
		char numc[4];

		if (count > 0) {
			printf("\n");
		}

		printf("\n解析する値を入力してください：");
		scanf("%s", numc);
		//numc配列に解析値を格納

		if (numc[0] == 'e') {
			break;
		}

		int numcc[3] = { numc[0] - '0', numc[1] - '0',numc[2] - '0'};
		//文字コードを数字コードに変換
		//解析する数値はnumcc配列[3]にint型で格納される

		int hit, blow;

		printf("hit数を入力してください：");
		scanf("%d", &hit);

		if (hit == 3) {
			printf("Win!\n");
			break;
		}

		printf("blow数を入力してください：");
		scanf("%d", &blow);

		//これと一致しないHit,Blow数を除外するため

		int hitc = 0;
		int blowc = 0;
		//ループ内で使用するカウント


		//long cpu_time;
		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {

						if (opt[i][j][k] == 't') {

							//printf("%d %d %d %d", numcc[0], numcc[1], numcc[2]);
							//OK

							int num[3] = { i ,j ,k };
							//num[3]配列にそれぞれ予測する値を格納(全探）
							//プレイモードで相手が決めている数の役割をnum[4]配列がうけもつ

							//printf("%d %d %d %d\n", num[0], num[1], num[2]);
							//OK

							hitc = 0;
							blowc = 0;
							//Hitc,Blowcのカウントをループ毎にリセット

							for (int m = 0; m < 3; m++) {

								if (num[m] == numcc[m]) {
									hitc++;
								}
								//位の数字が一致すればhitcに+1

								else {

									for (int n = 0; n < 3; n++) {

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

							opt[i][j][k] = 'f';
							//Hit,Blow数が同一にならなければopt[i][j][k]に'f'を代入

						}
				}
			}
		}

		printf("\n以下が考えられうる数です\n\n");

		int count30 = 0;
		//出力の改行用カウント

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {

						if (opt[i][j][k] == 't') {

							int output = i * 100 + j * 10 + k  ;
							printf("%03d ", output);
							//optの値が't'であるものを全て出力

							count30++;

							if (count30 == 30) {
								printf("\n");
								count30 = 0;
							}
						}
				}
			}
		}

		//cpu_time = clock();

		//printf("CPU時間： %d\n", cpu_time);

		count++;

	} while (count < 100);
	//解析回数が100回に達したらプログラムを終了する

	system("pause");

	return 0;
}