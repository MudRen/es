#include "../tsunami.h"

inherit "/d/eastland/island/war/i_warvalue";

void create()
{
    ::create();
    set_level(19);
    set_name("General Hamiya","�����ͽ���");
    add("id",({"general","hamiya"}) );
    set_short("��Զ���� ������");
    set_long(@LONG
��Զ������������ħ��Զ�����ӵ���ָ�ӣ������佫��ֱϽ���������ϲ�����
����ս�������µĴ�С�˺ۣ���.......������ɱ�����˱���Թ����׶�Ŷ��	
LONG
            );
    set("unit","λ");
    set("gender","male");
    set("race","daemon");
    set("alignment",-1000);
    set("time_to_heal",5);
    set("pursuing",1);
    set("killer",1);
    set_natural_armor(51,20);
    set_natural_weapon(35,15,25);
    set_perm_stat("str",22);
    set_perm_stat("dex",25);
    set_perm_stat("int",30);
    set_perm_stat("kar",20);
    set("max_hp",600);
    set("hit_points",600);
    set_skill("tactic",100);
    set_skill("parry",100);
    set_skill("longblade",100);
    set_skill("block",100);
    set("justice",15);
    set("tactic","flank");
    set("wealth/gold",150);
    set("special_defense",(["all":30,"none":20]) );
    set("aim_difficulty",(["critical":80,"vascular":10,"ganglion":0]) );

    wield_weapon(TWEP"sword3");
    equip_armor(TOBJ"shield2");
    equip_armor(TOBJ"helmet1");
    equip_armor(TOBJ"boot1");
    equip_armor(TOBJ"mail2");
}

