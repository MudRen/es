#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "wing boy", "����С�ܵ�" );
	add( "id", ({ "boy" }) );
	set_short( "����С�ܵ�" );
	set_long(@C_LONG
һ����ס����������С��������Լʮһ�����꣬ͷ�������������٣������ֵ���
��Ƭ��ԭ����Ϸ��ˣ��һ�Դ��۾�������ض������ƣ���ʱ������Χ��ת�����ü�
�ˡ�
C_LONG
        );
	set( "gender", "male" );
	set( "race","����" );
	set( "alignment", 100 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
        set( "player_invisible" ,1 );
}
