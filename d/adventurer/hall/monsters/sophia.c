#include "mudlib.h"
#include <daemons.h>

inherit MONSTER;

void init()
{
add_action("do_sit","sit");
}
void create ()
{

    ::create();
    set_level(15);
    set_name("Officer Sophia","��ǹ� ������");
    add("id",({"officer","sophia"}) );
    set_short("��ǹ� ������");
	set_long(@C_LONG
��ǹ� ��������һ���̷�������Ů���������ɰ�����������õ�Ц�ݡ�
������Ϊŵ�����ǵ�ͼ��ݹ��������Ү����������ð�պ�����Ȥ���ص���
����ð���߹����ռ����ϣ���������κ��й�ð�յĹ��£��������Աߵ�Ƥ
���������������������������㽫����˶����һЩ���ꡣ
C_LONG
	);
    set("alignment",500);
    set( "gender", "female" );
    set( "race", "elf");
    set( "unit", "��" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",18);
    set_perm_stat( "int",22);
    set_perm_stat( "karma",23);
    set_skill("unarmed",70);
    set_skill("parry",60);	
    set ("max_hp",400);
    set ("hit_points",400);
    set ("wealth", ([ "gold":100]) );
    set_natural_weapon(20,10,20);
	set_natural_armor(50,40);
	set ("aim_difficulty",([ "weakest":30,"vascular":10]) );
	set("special_defense", (["fire":10,"none":20,"cold":-10]) );
    set ("weight", 400);
    wield_weapon("/d/adventurer/hall/weapons/claw");
    equip_armor("/d/deathland/armour/cloth05");
    equip_armor("/d/deathland/armour/necklace01");
    equip_armor("/d/deathland/armour/gloves01");
}
int do_sit()
{
     int explore,total_points,EXPLORE1,num;
     explore  = (int)this_player()->query_explore_points();
     total_points=EXPLORE_D->query_total_explore(); 
     EXPLORE1=explore*10000/total_points;
     if (EXPLORE1 > 10000) EXPLORE1 =10000;
     if((string)this_player()->query("class") != "adventurer" ) {
     write("��ǹ� ������˵��: ���ֲ���ð���ߣ������ʲ������?\n");
     return 1;
     }
     if ((int)this_player()->query_level() < 4 )
     return notify_fail("��ǹ� ������˵��: ������ĵȼ�̫���ˣ����ܶ���û�а�����\n");
     if ((int)this_player()->query("adv_cash") < EXPLORE1 ) {
     tell_object(this_player(),set_color("�㿪ʼ�����������ð���¼��������Ǿ۾�����ļ�¼����ʱ��¶����ݵ�����\n\n", "HIG",this_player()) );
     	        tell_room( environment(this_player()),"\n"+
		this_player()->query("c_name")+"��������ʼ������׵Ĵ����Լ���ð������" 
		"������������Ȼ��ר�ĵ�������\n\n", this_player() );
     num = EXPLORE1 - (int)this_player()->query("adv_cash");
     this_player()->add("wealth/gold",num);
     this_player()->set("adv_cash",EXPLORE1);
     write("��ǹ� ������˵��: лл�㣬��Щ�Ǹ���ı���\n");
     if((string)this_player()->query("gender") != "male" ) return 1;
     else 
     write("��ǹ� ��������������������������һ��.\n");
     return 1;
     }
     write("��ǹ� ������˵��: �㲢û�и�������ð�չ��¡�\n"
           "��ӵ��ͣ��Ҷ����кܸߵ�����....\n");
     return 1;      
}     
