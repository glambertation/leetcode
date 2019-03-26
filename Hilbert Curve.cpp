https://blog.csdn.net/x_iya/article/details/78536132

int hilbertCurve(int x, int y, int iter) {
	if(iter == 0) return 1;
	int areaCnt = (1 << (iter * 2 - 2));
	int borderLen = (1 << (iter - 1));

	if(x>=borderLen && y>=borderLen)
		return areaCnt*2 + hilbertCurve(x-borderLEn, y-borderLen, iter -1);
	else if (x<borderLen && y >=borderLen)
		return areaCnt + hilbertCurve(x, y-borderLen, iter-1);
	else if (x < borderLen && y < borderLen)
		return hilbertCurve(y, x, iter -1);
	else
		return areaCnt*3 + hilbertCurve(borderLen -1 -y, 2*borderLen-1-x, iter-1);

}
