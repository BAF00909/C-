#pragma once

double generateSineWavefreq(int i) {
     return  (double)(3276 * sin(3.6 * i * 3.14/180) + 32767);
}

double CalculateError(double a, int b) {
	return a - b;
}

double Errorresult(double x, double y) {
	return x + y;
}

void Task2()
{
	std::vector<double> wavefreq(100);
	std::vector<int>wavefreq_int(100);
	int i = 0;
	std::generate(wavefreq.begin(), wavefreq.end(), [i]() mutable{
		i++;
		return generateSineWavefreq(i);
	});
	std::copy(wavefreq.begin(), wavefreq.end(), wavefreq_int.begin());
	for (auto elem : wavefreq_int)
	{
		std::cout << elem << std::endl;
	}
	
	double res = std::inner_product(wavefreq.begin(), wavefreq.end(), wavefreq_int.begin(), 0.0, Errorresult, CalculateError);

	std::cout << "Error: " << sqrt(res);

}
