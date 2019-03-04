#include "../zeus.h"
inherit MONSTER;

void create()
{       int i;
        ::create();
        set_level(19);
        set_name( "overseer", "������" );
        add ("id", ({ "overseer" }) );
        set_short( "�󹤹�ͷ ������");
        set("unit","λ");
        set_long(@C_LONG
����һλ�׺��Ķ���ǿ׳�Ĺ�ͷ�����еĿ��������Ͽ������£�û��
�˸Ҵ�����㣬��˵��ȥ��ר�����ܵ�������ģ���һ����Ե�ʻ��б�
���ϴ����ȣ������ϴ����������æ�������ϴα�ը�����˵Ĺ�ͷ
C_LONG
        );
        
        set("alignment",100);
        set("wealth/gold",50);
        set("gender", "male");
        set("race", "dwarf");
        set("max_hp", 800);
        set("max_fp", 600);
        set("hit_points", 800);
        set("force_points", 600);
        set_perm_stat("str", 27);
        set_perm_stat("dex", 26);
        set_natural_weapon( 30,20, 40 );
	set_natural_armor( 80, 30 );
        set("special_defense", ([ "all":40, "none":30 ]) );
        set("aim_difficulty", ([ "critical":40, "vascular":50, ]) );
        set_skill("longblade",90);
        set_skill("parry", 90);
	set("tactic_func","my_tactic");
	set("inquiry",([
	"key":
"�Ҳ������������ǰ�Ĺ�ͷ�������������Ǵα�ը����ʧ��\n"
"һ�����Ƭ�Ķ�����ϣ��������з������ƵĶ����ܻ�������\n"
])); 
	 wield_weapon(ZOBJ"/dragon_sword");
	 equip_armor(ZOBJ"/dragon_gloves");
	 equip_armor(ZOBJ"/love_ring.c");
	 equip_armor(ZOBJ"/six_shoe.c");
}
int my_tactic()
{       object *victim;
        int dam,bonus; 
        string *attack_msg=({
"\n������ٽ���ͷ�ϻ���Բ��ʹ��������̧ͷ���������ͷ������������������\n\n",
	              
"\n�����뽫���컨������˦������ǰ�Ϸ��Ƴ�ʹ��������ָ·������������㣡��\n\n",
	              
"\n����������������ϥ��˫���ƽ���ǰ�ʹ�ʹ������������������������࣡����\n\n",
	              
"\n���������̤ʵ�����ֳֽ����滨ʹ�����������ࣾ�������ֱۣ���������\n\n",
	              
"\n���������ֳֽ��������ã����컨ʹ������չ��ü����������������㣡������\n\n",
	              
"\n���������ֳֽ�������ǰ�·�����ʹ����������������������������㣡������\n\n"
	              });
	bonus=(int)this_player()->query_perm_stat("dex");
	if(!(victim=query_attackers())|| ( random(20)>5 ) ) return 0;
	tell_object(victim,attack_msg[random(6)]);
	dam = 60+random(30)-bonus*2;
	victim->receive_special_damage("divine",dam);
	return 1;
	}