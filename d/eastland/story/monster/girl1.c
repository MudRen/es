#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "wing girl", "����С����" );
	add( "id", ({ "girl" }) );
	set_short( "����С����" );
	set_long(@C_LONG
һ����ס����������С��������Լʮһ�����꣬ͷ�ϰ���һ����β���ӣ�һ����
����Ĵ��ۣ�ģ�����ǿɰ���СŮ�����ں�����ͬ��׷����Ϸ����ʱ�������ֵ�Ц
����
C_LONG
        );
	set( "gender", "female" );
	set( "alignment", 100 );
        set( "race","����" );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
        set( "player_invisible" ,1 );
}
