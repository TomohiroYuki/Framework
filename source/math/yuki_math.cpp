
#include "yuki_math.h"
//#include <cmath>
//#include "math.h"
//#define _ITERATOR_DEBUG_LEVEL  0
#define PI (3.14159265f)

#define TABLE_SIXE_ATAN   (577)
#define BLOCK_NUM_ATAN    (26)
#define DEBIDE_ONE_BLOCK_ATAN  (24)

const float atan_table[] = {

	0.0f,		  0.010757872f, 0.021513255f, 0.032263662f, 0.043006614f, 0.053739643f, 0.064460294f, 0.075166127f, 0.085854727f, 0.096523698f, 0.107170672f, 0.117793313f, 0.128389314f, 0.138956406f, 0.149492357f, 0.159994976f, 0.170462116f, 0.180891675f, 0.191281599f, 0.201629882f, 0.211934573f, 0.222193772f, 0.232405634f, 0.242568372f,
	0.252680255f, 0.257352920f, 0.262014120f, 0.266663696f, 0.271301491f, 0.275927351f, 0.280541124f, 0.285142663f, 0.289731822f, 0.294308458f, 0.298872432f, 0.303423606f, 0.307961847f, 0.312487024f, 0.316999008f, 0.321497674f, 0.325982900f, 0.330454567f, 0.334912556f, 0.339356756f, 0.343787055f, 0.348203345f, 0.352605521f, 0.356993480f,
	0.361367124f, 0.365095906f, 0.368814090f, 0.372521617f, 0.376218433f, 0.379904483f, 0.383579714f, 0.387244075f, 0.390897517f, 0.394539990f, 0.398171448f, 0.401791846f, 0.405401139f, 0.408999285f, 0.412586242f, 0.416161972f, 0.419726435f, 0.423279595f, 0.426821416f, 0.430351863f, 0.433870904f, 0.437378508f, 0.440874644f, 0.444359282f,
	0.447832397f, 0.451109913f, 0.454377055f, 0.457633802f, 0.460880135f, 0.464116036f, 0.467341488f, 0.470556474f, 0.473760979f, 0.476954988f, 0.480138489f, 0.483311469f, 0.486473916f, 0.489625820f, 0.492767171f, 0.495897961f, 0.499018181f, 0.502127824f, 0.505226885f, 0.508315358f, 0.511393238f, 0.514460523f, 0.517517208f, 0.520563293f,
	0.523598776f, 0.526620037f, 0.529630722f, 0.532630831f, 0.535620366f, 0.538599331f, 0.541567728f, 0.544525562f, 0.547472837f, 0.550409559f, 0.553335734f, 0.556251369f, 0.559156472f, 0.562051050f, 0.564935113f, 0.567808670f, 0.570671730f, 0.573524306f, 0.576366408f, 0.579198048f, 0.582019238f, 0.584829993f, 0.587630324f, 0.590420247f,
	0.593199776f, 0.596070153f, 0.598929395f, 0.601777519f, 0.604614546f, 0.607440494f, 0.610255383f, 0.613059233f, 0.615852066f, 0.618633903f, 0.621404766f, 0.624164678f, 0.626913661f, 0.629651740f, 0.632378937f, 0.635095277f, 0.637800786f, 0.640495489f, 0.643179410f, 0.645852577f, 0.648515016f, 0.651166754f, 0.653807818f, 0.656438236f,
	0.659058036f, 0.661846794f, 0.664623487f, 0.667388151f, 0.670140820f, 0.672881532f, 0.675610323f, 0.678327232f, 0.681032294f, 0.683725549f, 0.686407034f, 0.689076788f, 0.691734851f, 0.694381261f, 0.697016059f, 0.699639283f, 0.702250975f, 0.704851175f, 0.707439924f, 0.710017262f, 0.712583230f, 0.715137872f, 0.717681227f, 0.720213338f,
	0.722734248f, 0.725495070f, 0.728242439f, 0.730976412f, 0.733697045f, 0.736404397f, 0.739098525f, 0.741779486f, 0.744447339f, 0.747102142f, 0.749743953f, 0.752372831f, 0.754988834f, 0.757592022f, 0.760182452f, 0.762760186f, 0.765325280f, 0.767877795f, 0.770417790f, 0.772945324f, 0.775460457f, 0.777963247f, 0.780453756f, 0.782932041f,
	0.785398163f, 0.788179843f, 0.790946048f, 0.793696864f, 0.796432378f, 0.799152678f, 0.801857849f, 0.804547978f, 0.807223153f, 0.809883458f, 0.812528982f, 0.815159808f, 0.817776025f, 0.820377717f, 0.822964970f, 0.825537869f, 0.828096501f, 0.830640950f, 0.833171301f, 0.835687639f, 0.838190048f, 0.840678613f, 0.843153417f, 0.845614545f,
	0.848062079f, 0.850916623f, 0.853752701f, 0.856570447f, 0.859369995f, 0.862151476f, 0.864915021f, 0.867660763f, 0.870388831f, 0.873099356f, 0.875792467f, 0.878468291f, 0.881126958f, 0.883768595f, 0.886393327f, 0.889001282f, 0.891592584f, 0.894167357f, 0.896725726f, 0.899267814f, 0.901793743f, 0.904303634f, 0.906797610f, 0.909275789f,
	0.911738291f, 0.914730510f, 0.917699648f, 0.920645919f, 0.923569535f, 0.926470708f, 0.929349646f, 0.932206557f, 0.935041647f, 0.937855119f, 0.940647176f, 0.943418019f, 0.946167846f, 0.948896854f, 0.951605240f, 0.954293195f, 0.956960913f, 0.959608583f, 0.962236393f, 0.964844532f, 0.967433182f, 0.970002529f, 0.972552753f, 0.975084034f,
	0.977596551f, 0.980820774f, 0.984014240f, 0.987177322f, 0.990310389f, 0.993413807f, 0.996487934f, 0.999533127f, 1.002549736f, 1.005538108f, 1.008498584f, 1.011431503f, 1.014337197f, 1.017215996f, 1.020068224f, 1.022894201f, 1.025694244f, 1.028468665f, 1.031217772f, 1.033941868f, 1.036641254f, 1.039316225f, 1.041967073f, 1.044594087f,
	1.047197551f, 1.050816532f, 1.054390334f, 1.057919707f, 1.061405388f, 1.064848102f, 1.068248556f, 1.071607449f, 1.074925461f, 1.078203264f, 1.081441514f, 1.084640858f, 1.087801926f, 1.090925341f, 1.094011711f, 1.097061633f, 1.100075693f, 1.103054467f, 1.105998519f, 1.108908401f, 1.111784658f, 1.114627821f, 1.117438414f, 1.120216949f,
	1.122963930f, 1.127330758f, 1.131618749f, 1.135829864f, 1.139966008f, 1.144029026f, 1.148020710f, 1.151942800f, 1.155796981f, 1.159584890f, 1.163308116f, 1.166968202f, 1.170566645f, 1.174104897f, 1.177584370f, 1.181006435f, 1.184372422f, 1.187683625f, 1.190941299f, 1.194146664f, 1.197300905f, 1.200405176f, 1.203460595f, 1.206468251f,
	1.209429203f, 1.215714658f, 1.221794011f, 1.227676808f, 1.233372042f, 1.238888190f, 1.244233248f, 1.249414762f, 1.254439860f, 1.259315275f, 1.264047377f, 1.268642189f, 1.273105415f, 1.277442457f, 1.281658436f, 1.285758207f, 1.289746377f, 1.293627320f, 1.297405190f, 1.301083937f, 1.304667315f, 1.308158896f, 1.311562083f, 1.314880112f,
	1.318116072f, 1.320263800f, 1.322376074f, 1.324453746f, 1.326497641f, 1.328508560f, 1.330487279f, 1.332434549f, 1.334351101f, 1.336237642f, 1.338094857f, 1.339923414f, 1.341723957f, 1.343497116f, 1.345243498f, 1.346963696f, 1.348658284f, 1.350327820f, 1.351972846f, 1.353593890f, 1.355191464f, 1.356766066f, 1.358318180f, 1.359848278f,
	1.361356817f, 1.363083741f, 1.364782820f, 1.366454714f, 1.368100059f, 1.369719474f, 1.371313560f, 1.372882898f, 1.374428053f, 1.375949572f, 1.377447985f, 1.378923810f, 1.380377547f, 1.381809681f, 1.383220686f, 1.384611020f, 1.385981128f, 1.387331443f, 1.388662387f, 1.389974370f, 1.391267788f, 1.392543028f, 1.393800468f, 1.395040474f,
	1.396263402f, 1.400963134f, 1.405418652f, 1.409648344f, 1.413668815f, 1.417495093f, 1.421140810f, 1.424618364f, 1.427939049f, 1.431113175f, 1.434150176f, 1.437058698f, 1.439846679f, 1.442521418f, 1.445089642f, 1.447557558f, 1.449930901f, 1.452214980f, 1.454414716f, 1.456534675f, 1.458579101f, 1.460551946f, 1.462456888f, 1.464297361f,
	1.466076572f, 1.470258602f, 1.474120439f, 1.477697396f, 1.481019792f, 1.484113802f, 1.487002139f, 1.489704608f, 1.492238555f, 1.494619236f, 1.496860124f, 1.498973161f, 1.500968966f, 1.502857019f, 1.504645803f, 1.506342936f, 1.507955277f, 1.509489018f, 1.510949764f, 1.512342597f, 1.513672142f, 1.514942611f, 1.516157854f, 1.517321391f,
	1.518436449f, 1.519504719f, 1.520530305f, 1.521515715f, 1.522463261f, 1.523375083f, 1.524253163f, 1.525099338f, 1.525915316f, 1.526702682f, 1.527462915f, 1.528197394f, 1.528907404f, 1.529594147f, 1.530258748f, 1.530902260f, 1.531525671f, 1.532129907f, 1.532715841f, 1.533284289f, 1.533836024f, 1.534371770f, 1.534892214f, 1.535398001f,
	1.535889742f, 1.537285755f, 1.538574438f, 1.539767707f, 1.540875777f, 1.541907456f, 1.542870378f, 1.543771194f, 1.544615723f, 1.545409080f, 1.546155778f, 1.546859815f, 1.547524745f, 1.548153737f, 1.548749628f, 1.549314964f, 1.549852035f, 1.550362910f, 1.550849459f, 1.551313378f, 1.551756212f, 1.552179364f, 1.552584119f, 1.552971650f,
	1.553343034f, 1.554041135f, 1.554685542f, 1.555282221f, 1.555836284f, 1.556352140f, 1.556833608f, 1.557284015f, 1.557706274f, 1.558102943f, 1.558476280f, 1.558828284f, 1.559160733f, 1.559475212f, 1.559773140f, 1.560055791f, 1.560324309f, 1.560579729f, 1.560822986f, 1.561054929f, 1.561276329f, 1.561487889f, 1.561690252f, 1.561884002f,
	1.562069681f, 1.563316326f, 1.564251319f, 1.564978540f, 1.565560318f, 1.566036319f, 1.566432987f, 1.566768630f, 1.567056323f, 1.567305658f, 1.567523825f, 1.567716326f, 1.567887438f, 1.568040538f, 1.568178328f, 1.568302995f, 1.568416329f, 1.568519808f, 1.568614663f, 1.568701930f, 1.568782484f, 1.568857071f, 1.568926331f, 1.568990814f,
	1.569050998f, 1.569526996f, 1.569798996f, 1.569974995f, 1.570098195f, 1.570189256f, 1.570259302f, 1.570314857f, 1.570359994f, 1.570397394f, 1.570428889f, 1.570455775f, 1.570478994f, 1.570499249f, 1.570517074f, 1.570532881f, 1.570546994f, 1.570559672f, 1.570571123f, 1.570581517f, 1.570590994f, 1.570599670f, 1.570607643f, 1.570614994f,
	1.570621794f, 1.570669394f, 1.570696594f, 1.570714194f, 1.570726514f, 1.570735620f, 1.570742624f, 1.570748180f, 1.570752694f, 1.570756434f, 1.570759583f, 1.570762272f, 1.570764594f, 1.570766619f, 1.570768402f, 1.570769982f, 1.570771394f, 1.570772661f, 1.570773806f, 1.570774846f, 1.570775794f, 1.570776661f, 1.570777458f, 1.570778194f,
	1.570778874f, 1.570783633f, 1.570786353f, 1.570788113f, 1.570789345f, 1.570790256f, 1.570790957f, 1.570791512f, 1.570791963f, 1.570792337f, 1.570792652f, 1.570792921f, 1.570793153f, 1.570793356f, 1.570793534f, 1.570793692f, 1.570793833f, 1.570793960f, 1.570794075f, 1.570794179f, 1.570794273f, 1.570794360f, 1.570794440f, 1.570794513f,
	1.570794581f

};

const float atan_table_width[] =
{
	0.010758287f,
	0.004990233f,
	0.004267500f,
	0.004040242f,
	0.004035400f,
	0.004183200f,
	0.004471685f,
	0.004920121f,
	0.005578892f,
	0.006545876f,
	0.008010219f,
	0.010367130f,
	0.014567300f,
	0.023503555f,
	0.051134668f,
	0.034651948f,
	0.040277155f,
	0.160128443f,
	0.398615510f,
	0.398129858f,
	1.193904514f,
	2.387445354f,
	19.09869013f,
	214.8591950f,
	2148.591734f,
	21485.91732f
};

const float atan_table_delimit_val[] =
{
	0.0f       ,
	0.258198890f,
	0.377964473f,
	0.480384461f,
	0.577350269f,
	0.674199862f,
	0.774596669f,
	0.881917104f,
	1.0f       ,
	1.133893419f,
	1.290994449f,
	1.483239697f,
	1.732050808f,
	2.081665999f,
	2.645751311f,
	3.872983346f,
	4.704630109f,
	5.671281820f,
	9.514364454f,
	19.08113669f,
	28.63625328f,
	57.28996163f,
	114.5886501f,
	572.9572134f,
	5729.577893f,
	57295.77951f,
	572957.7951f
};



float YMatanf(float x)
{
	int i;
	float index;
	int index_int;
	float index_dec;


	if (x<.0f) return -YMatanf(-x);
	if (x == 0.0f)   return 0.0f;
	for (i = 1; i <= BLOCK_NUM_ATAN; i++)
	{
		if (x <= atan_table_delimit_val[i])
		{
			index = DEBIDE_ONE_BLOCK_ATAN * (i - 1) + ((x - atan_table_delimit_val[i - 1]) / atan_table_width[i - 1]);
			index_int = (int)index;
			index_dec = index - (float)index_int;
			return atan_table[index_int] + index_dec * ((atan_table[index_int + 1] - atan_table[index_int]));
		}
	}
	return atan_table[TABLE_SIXE_ATAN - 1];

}

float YMatan2f(float y, float x)
{
	if (x >  0.0f) return YMatanf(y / x);
	if (y >= 0.0f &&  x <  0.0f) return YMatanf(y / x) + PI;
	if (y <  0.0f &&  x <  0.0f) return YMatanf(y / x) - PI;
	if (y >  0.0f &&  x == 0.0f) return PI / 2.0f;
	if (y <  0.0f &&  x == 0.0f) return -PI / 2.0f;
	if (y == 0.0f &&  x == 0.0f) return 0.0f; 
	return 0.0f;
}







bool HitCheck3DCapsule(VECTORIII s_point, VECTORIII e_point, float r1, VECTORIII P, float r2)
{

	//������AB�A�P�_��P�AP��ʂ�AB�ւ̐�����AB�̌�_��Q�APQ�̒�����d�Ƃ���B
	//�����ł͓_��x�N�g���𖾎��I�ɂ��邽�߁A�����K���𖳎�������̂Ƃ���B
	VECTORIII AtoB = e_point - s_point;
	VECTORIII AtoP = P - s_point;
	float dot_point = AtoB.x*AtoP.x + AtoB.y*AtoP.y + AtoB.z*AtoP.z;
	float ABlength = AtoB.LengthSq();
	if (ABlength == .0f)
	{
		if (r1 + r2 > AtoP.Length())
			return true;
		else return false;
	}

	float dot_per_length = dot_point / ABlength;
	VECTORIII Q = s_point + AtoB*dot_per_length;
	VECTORIII PtoQ = P - Q;
	if (0 < dot_per_length&&dot_per_length < 1)
	{
		if (r1 + r2 > PtoQ.Length())
			return true;

	}
	else
	{
		if (r1 + r2 > AtoP.Length())
			return true;

		VECTORIII BtoP = P - e_point;
		if (r1 + r2 > BtoP.Length())
			return true;
	}

	return false;
}



bool HitCheck2DCapsule(VECTORII s_point, VECTORII e_point, float r1, VECTORII p, float r2, VECTORII& OUT_VECT, float& OUT_R)
{
	//������AB�A�P�_��P�AP��ʂ�AB�ւ̐�����AB�̌�_��Q�APQ�̒�����d�Ƃ���B
	VECTORII AtoB = e_point - s_point;
	VECTORII AtoP = p - s_point;
	float dot_point = AtoB.x*AtoP.x + AtoB.y*AtoP.y;
	float ABlength = AtoB.LengthSq();
	if (ABlength == .0f)
	{
		if (r1 + r2 > AtoP.Length()) {
			OUT_VECT = AtoB;
			OUT_R = AtoP.Length();
			return true;
		}
		else return false;
	}

	float dot_per_length = dot_point / ABlength;
	VECTORII Q = s_point + AtoB*dot_per_length;
	VECTORII PtoQ = p - Q;
	if (0 < dot_per_length&&dot_per_length < 1)
	{
		if (r1 + r2 > PtoQ.Length())
		{
			OUT_VECT = AtoB;
			OUT_R = 1.0f - (PtoQ.Length() / (r1 + r2));
			return true;
		}


	}
	else
	{
		if (r1 + r2 > AtoP.Length()) {

			OUT_VECT = AtoB;

			OUT_R = 1.0f - (AtoP.Length() / (r1 + r2));
			return true;
		}
		VECTORII BtoP = p - e_point;
		if (r1 + r2 > BtoP.Length())
		{
			OUT_VECT = AtoB;
			OUT_R = 1.0f - (BtoP.Length() / (r1 + r2));
			return true;
		}

	}

	return false;
}

bool HitCheck2DCapsule(VECTORII s_point, VECTORII e_point, float r1, VECTORII p, float r2)
{
	//������AB�A�P�_��P�AP��ʂ�AB�ւ̐�����AB�̌�_��Q�APQ�̒�����d�Ƃ���B
	VECTORII AtoB = e_point - s_point;
	VECTORII AtoP = p - s_point;
	float dot_point = AtoB.x*AtoP.x + AtoB.y*AtoP.y;
	float ABlength = AtoB.LengthSq();
	if (ABlength == .0f)
	{
		if (r1 + r2 > AtoP.Length()) {
			return true;
		}
		else return false;
	}

	float dot_per_length = dot_point / ABlength;
	VECTORII Q = s_point + AtoB*dot_per_length;
	VECTORII PtoQ = p - Q;
	if (0 < dot_per_length&&dot_per_length < 1)
	{
		if (r1 + r2 > PtoQ.Length())
		{
			return true;
		}


	}
	else
	{
		if (r1 + r2 > AtoP.Length()) {
			return true;
		}
		VECTORII BtoP = p - e_point;
		if (r1 + r2 > BtoP.Length())
		{
			return true;
		}

	}

	return false;
}