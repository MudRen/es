#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "Ninjadog Poppy", "��Ȯ �ͱ�" );
	add( "id", ({ "ninjadog","dog","poppy" }) );
	set_short( "Ninjadog Poppy", "��Ȯ �ͱ�" );
	set_long(@AAA
����һֻ���͵Ĵ󹷣�����ܹ��̷���ѵ�����б�һ�㾯��Ȯ�и�ǿ��
ս�����ǼӶ����صİ�Ȯ��
AAA
 );
	set( "unit", "ֻ" );
	set( "race", "monster" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 25 );    
        set( "max_hp",350 );
        set( "hit_points",350 );
 	set_natural_armor( 60,25 );
	set( "natural_weapon_class1", 60 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":15,"none":15 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":15,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "ͷ��", "����", "ǰ��", "�ʺ�","����","β��" }) );
        set_skill( "tactic",100 );
        set("tactic","berserk");
        set( "wealth" , ([ "silver": 70 ]) );
        set_c_verbs( ({"%s�嵽����ǰ������Ŷ�%sһ������","%sͻȻ��ʧ���ӿ���������ײ%s",
                       "%s���˹���������צץ��%s"}));    
}
