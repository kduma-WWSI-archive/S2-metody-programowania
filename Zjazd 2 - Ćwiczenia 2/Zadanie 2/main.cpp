#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;



float *create_array ( int &n ) {
	return new float[n];
}

int define_array_size(){
	int n;

	cout << "Podaj rozmiar tablicy: ";
	cin >> n;

	return n;
}

void generate_values(float *array, int elements_count){
	srand(time(0));
	for(int i = 0; i < elements_count; i++)
		*(array + i) = 100.0*rand()/RAND_MAX;
}

void display_table(float *array, int elements_count, char *title){
	cout << title << ": ";
	for(float *wsk = array; wsk < array+elements_count; wsk++)
		cout << *wsk << ", ";
	cout << endl;
}
void display_value(float value, char *title){
	cout << title << ": " << value << endl;
}

float avg(float *array, int elements_count){
	float avg = 0;

	for(float *wsk = array; wsk < array+elements_count; wsk++)
		avg += *wsk;

	avg /= elements_count+1;

	return avg;
}

float var(float *array, int elements_count, float average){
	float var = 0;

	for(float *wsk = array; wsk < array+elements_count; wsk++)
		var += sqrt(*wsk + average);

	var /= elements_count+1;

	return var;
}

float *var_elements(float *array, int elements_count, float average, float &variation, int &len){
	len = 0;

	for(float *wsk = array; wsk < array+elements_count; wsk++)
		if(*wsk > average-variation && *wsk < average+variation)
			len += 1;

	float *var = create_array(len);

	int counter = 0;
	for(float *wsk = array; wsk < array+elements_count; wsk++)
		if(*wsk > average-variation && *wsk < average+variation)
			var[counter++] = *wsk;

	return var;
}


int main () {
	float *a, *b;
	int a_size = define_array_size();

	a = create_array(a_size);
	generate_values(a, a_size);
	display_table(a, a_size, "Tablica a");
	float a_avg = avg(a, a_size);
	display_value(a_avg, "Średnia tablicy a");
	float a_var = var(a, a_size, a_avg);
	display_value(a_var, "Odchylenie tablicy a");

	int b_size = 0;
	b = var_elements(a, a_size, a_avg, a_var, b_size);
	display_table(b, b_size, "Tablica b");

}