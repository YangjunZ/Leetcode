#include <iostream>
#include <vector>

#include <cstdarg>
using namespace std;
// https://oj.leetcode.com/problems/maximum-gap/solution/
//for N num, avg gap is (max-min)/(N-1), therefore max gap is not smaller than avg gap and not smaller than the max gap in bucket.
//divide N num into (N-1) bucket, the max gap between gaps is the max gap of this problem.



class Solution
{
public:

	void maxmin(int a, int b, int *min, int *max)
	{
		if ( a <= b) {
			if ( a < *min )
				*min = a;
			if ( *max < b)
				*max = b;
		} else {
			if ( b < *min)
				*min = b;
			if ( *max < a)
				*max = a;
		}
	}

	void getMaxMin(vector<int> &num, int *min, int *max)
	{
		if ( num.size() == 0) {
			*min = -1;
			*max = -1;
			return ;
		}

		if ( num.size() == 1) {
			*min = num[0];
			*max = num[0];
			return ;
		}

		int tmp_min = 0x07fffffff;
		int tmp_max = 0;
		for (int i = 1; i < num.size(); i += 2) {
			maxmin(num[i - 1], num[i], &tmp_min, &tmp_max);
		}
		maxmin(num[num.size()-1],num[num.size()-1], &tmp_min, &tmp_max);
		*min = tmp_min;
		*max = tmp_max;
	}

	int maximumGap(vector<int> &num)
	{
		//getMaxMin
		//divide N num to N-1 buckets,
		//get max and min of N-1 buckets
		//get the max gap between N-1 buckets
		// N less than 2, return 0, N equals to 2, return abs( a-b)
		int max_num = 0, min_num = 0x7fffffff;
		if(num.size() < 2)
			return 0;
		
		if(num.size() == 2){
			maxmin(num[0], num[1], &min_num, &max_num);
			// cout<<"max:"<<max_num << " min:"<<min_num<<endl;
			return max_num - min_num;
		}

		// std::vector<int> * buckets = new std::vector<int>[num.size()]; //leetcode error
		std::vector<  std::vector<int> > buckets;
		std::vector<int> max_v;
		std::vector<int> min_v;
		getMaxMin(num, &min_num, &max_num);

		// cout<<"max:"<<max_num << " min:"<<min_num<<endl;
		//how to gen N-1 avg bucket, avg_len = (max -min)/(N-1), bucket index = (x - min)/avg_len
		for(int i=0; i<num.size(); i++){
			std::vector<int> v;
			buckets.push_back(v);
		}
		int index = 0;
		for (int i = 0; i < num.size(); i++) {
			//overflow
			index = (long long) (num[i] - min_num) * (long long)(num.size() - 1) / (long long)(max_num - min_num);
			buckets[index].push_back( num[i]);
		}
		int tmp_max, tmp_min;
		for (int i = 0; i < num.size(); i++) {
			getMaxMin( buckets[i], &tmp_min, &tmp_max);
			cout << "(" << tmp_max << "," <<tmp_min<< ")"<<endl;
			max_v.push_back( tmp_max);
			min_v.push_back( tmp_min);
		}

		int max_gap = 0;
		int i = 0;
		int pre_max = -1;
		while ( i < max_v.size() ) {
			if ( max_v[i] != -1) {
				if (pre_max != -1 &&  min_v[i] - pre_max > max_gap) {
					max_gap = min_v[i] - pre_max;
				}
				pre_max = max_v[i];
			}
			i++;
		}

		return max_gap;
	}

	void test(int length, ...)
	{
		va_list pvar;
		std::vector<int> vint;
		va_start( pvar, length);
		for (int i = 0; i < length; i++) {
			vint.push_back( va_arg( pvar, int));
		}
		va_end(pvar);
		cout<<endl;
		cout << maximumGap( vint) << endl;
	}
};

int main()
{
	Solution ss;
	ss.test(2, 1, 10000000);
	ss.test(2, 2, 1);
	ss.test(3, 5, 2, 3);
	ss.test(4, 3, 6, 9, 1);
	ss.test(197,601408776,63967816,431363697,242509930,15970592,60284088,228037800,147629558,220782926,55455864,456541040,106650540,17290078,52153098,103139530,294196042,16568100,426864152,61916064,657788565,166159446,1741650,101791800,28206276,6223796,524849590,125389882,84399672,153834912,164568204,1866165,283209696,560993994,16266096,219635658,9188983,485969304,782013650,120332636,44659356,444517408,36369045,47370708,18542592,98802990,137690000,124889895,56062800,265421676,309417680,4634176,801661539,510541206,258227892,398938089,47255754,152260962,409663140,102847688,45756553,377936600,269498,375738702,263761134,53797945,329493948,224442208,508336845,189507850,40944620,127879560,119629476,186894520,62409156,693721503,4289916,523899936,28955240,266488028,20356650,40769391,483694272,97988044,84102,67246047,310688630,41288643,58965588,42881432,152159462,94786355,174917835,119224652,525034376,261516,274800528,62643819,23613832,8397240,797832131,855155367,337066320,26341480,61932200,20661075,515542796,390337500,522552030,43538516,150800550,116747540,152989123,488640056,700610304,233604,344277340,21439176,9397864,16365822,73027584,453041413,197374275,157735188,15273822,187081152,379611084,865005504,223099767,80478651,377729400,186738219,34738263,16634072,112791343,99631856,119364960,477106486,583953920,624509809,188442472,294181256,213023715,146645884,149530380,497592753,132170327,72770643,126683010,405141255,590214306,26670714,95582385,162080790,231120099,8946432,204967980,592849110,54120698,375915096,602145859,5346440,226337825,425156369,653591624,578483360,572410800,32290700,381384563,149939976,183225375,155695620,38307636,457513760,97085778,75200576,8068176,221650296,556889418,252495726,895020231,19932465,156334887,191383314,348432526,368701264,14315598,148936587,279419435,237325542,252587218,322929504,26331343,355297676,600420786,652017765,51673622,159015675);
	return 0;
}