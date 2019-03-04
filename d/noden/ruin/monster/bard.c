// bard.c

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(19);
    set_name("Bard Xerox", "����ʫ�� ����˹");
    add("id", ({"bard", "xerox"}));
    set_short("����ʫ�� ����˹");
    set_long(@C_LONG
����ɫ��ͷ����տ�����۾����������ڰ�������е���ɫ��������ʫ�˶�
�еĵ����ɵ����������ʣ��㷢������˹�Ǹ����������Ļ���塣�ţ������
˵�Ǻ������������ˡ����������������������������ѿ���������������Ҫ��
�����������������Ķࡣ
C_LONG
     	);
    set_perm_stat("str", 30);
    set_perm_stat("con", 25);
    set_perm_stat("int", 30);
    set_perm_stat("dex", 20);
    set_perm_stat("pie", 20);
    set_perm_stat("kar", 20);
    set_skill("dodge", 100);
    set_skill("blunt", 85);
    set("race", "drow");
    set("gender", "male");
    set("hit_points", 1200);
    set("max_hp", 1200);
    set("aim_difficulty", (["critical" : 80, "weakest" : 80]));
    set("special_defense", (["all" : 30, "none" : 30, "monk" : 20, "scholar" : 20]));
    set_natural_armor(30, 40);
    set_natural_weapon(20, 25, 40);
    wield_weapon(WP"flute.c");
    equip_armor("/d/deathland/armour/cloth03.c");
    set("chat_chance", 10);
    set("chat_output", ({
	"����˹������������һ���ǣ����Բ����ԣ���\n",
	"����˹�������������ҵ����ϣ���������ǡ���\n",
	"����˹��������Seven lonely days make a lonely week ...��\n", 
	"����˹��������Seven lonely nights make a lonely me ...��\n"
	}));
    set("inquiry", ([
	"carmue" : "@@ask_carmue",
	"paladin" : "@@ask_carmue", 
	"statue" : "@@ask_statue"
	]));
}

void ask_carmue(object p)
{
    tell_object(p, @CARMUE
��˵�Ǹ����ѽ������Ů������������ʿ֮һ� .... �׵ĺ��� .... û�²�Ҫ��
������������ȥ���Ϻ��ݲ�Ǻ� ....
CARMUE
		);
    return;
}

void ask_statue(object p)
{
    tell_object(p, @STATUE
�Ǹ����ǵ������Ǹ���Ϊ͵�����⵽Ů������Ŀ���Ů�ˡ�����㻹�е�ͬ����
�Ļ���ժ (pick) ���仨ȥ���ڼ�̳�ϰɡ�
STATUE
		);
    return;
}

