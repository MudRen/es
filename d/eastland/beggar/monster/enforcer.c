#include "../dony.h"

inherit MONSTER;

void create()
{
     ::create();
     set_level(16);
     set_name( "church enforcer", "����ִ��ɮ" );
     add( "id", ({ "enforcer"}) );
     set_short( "����ִ��ɮ" );
     set_long(@C_LONG
����ִ��ɮ���������Ժ���Ĺ�Ͻ,ƽʱֻ�����ɨ���û��ߴ���Ժ����ְ����
�����æ,��Ϊ�����䵽��,����û�����㡣
C_LONG
	);
     set( "unit", "��" );
     set( "race", "human" );
     set( "gender", "male" );
     set( "alignment", 100 );
     set_perm_stat( "str", 20 );
     set_perm_stat( "dex", 22 );
     set_perm_stat( "int", 17 );
     set_perm_stat( "pie", 18 );
     set_skill( "dodge", 90 );
     set_skill( "tactic", 90 );
     set( "tactic", "assault" );
     set( "wealth/gold", 50 );
     set( "pursuing", 1 );
     set_natural_armor( 60,15 );
     set_natural_weapon(0,3,3);
     wield_weapon(DWEAPON"broom");
     equip_armor(DARMOR"enforcer_robe");
}
