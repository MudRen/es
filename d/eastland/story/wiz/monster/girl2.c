#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "girl", "СŮ��" );
	set_short( "СŮ��" );
	set_long(@C_LONG
һ����ס�ڡ����̳ǡ����С��������Լ�ߡ����꣬ͷ�������������٣�һ�Դ���
�����������Χ��һ����Ϸ�����ü��ˡ�
C_LONG
        );
	set( "gender", "female" );
        set_natural_armor(25,0); 
        set_natural_weapon( 7,1,3 );
}
