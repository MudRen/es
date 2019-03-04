#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(19);
    set_name("Lin Chong","�ֳ�");
    add("id",({"lin","chong"}) );
    set_short("�ֳ�");
	set_long(@C_LONG
��ű�\��ͷ�������ˣ����Թ�ֱ�������ú������վ�ǿ����ʹ�ɰ���ì
����Ϊ������ʮ������ܽ�ͷ���������ݺ������ݡ���Ϊ��ɽ�����
�廢���еڶ��󽫣���������æ��ѵ����ʿ��
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",23);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",25);
    set_skill("polearm",100);
    set_skill("parry",100);	
    set ("max_hp",1000);
    set ("hit_points",1000);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
        set("stun_difficulty/ma",20) ;
    set ("weight", 400);
    equip_armor(TARMOR"iron_helmet");
    wield_weapon(TWEAPON"snake_polearm");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"floral_plate");
    equip_armor(TARMOR"floral_cape");
    equip_armor(TARMOR"whitejade_ring");
}

