#include "../takeda.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(16);
	set_name("Wu Yong", "����");
	add ("id", ({ "wu", "yong" }) );
	set_short( "����");
	set_long(
		"����Ƕ��ǣ�۩�����ˣ���Ŷ��ǣ�������ı��Ϊ��ɽ����ܻ��ܾ�\n"
		"ʦ�����������֮�ơ�������ɽկ�ڿ����κβ�ƽ�������������\n" 
		"��������Ľ������������һ������ǰ����Ŀ��ת����\n"
		);
	set_perm_stat("str", 15);
	set_perm_stat("dex", 25);
	set_perm_stat("int",30);
	set_skill( "parry", 50 );
	set_skill( "dodge", 80 );
	set( "max_hp", 460 );
	set( "hit_points", 460 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1000 );
	set_natural_armor( 80, 28 );
	set_natural_weapon( 35, 15, 40 );
	set("special_defense", ([ "all":40, "none":20 ]) );
	set("inquiry",([ "meat":"@@ask_meat" ]));
	               
	set("aim_difficulty",
			([ "vascular":45, "ganglion":60 ]) );
	set( "tactic_func", "my_tactic" );

	wield_weapon("/d/eastland/goomay/obj/iron_chain");
	equip_armor(TARMOR"scholar_hood");
        equip_armor(TARMOR"sun_book");
        equip_armor(TARMOR"jade_cloth");
        equip_armor(TARMOR"scholar_cape");
}

int my_tactic()
{
	object *atk;

	if( !(atk = query_attackers()) || random(20)<16) return 0;
	else {
	tell_room(environment(this_object()), 
	"�������: �����񣬵����������ѣ�������һ�����ѻ�Ϊ����\n"
	"һ����â�ᴩ���õ�����......\n",
	this_object());
	this_object()->receive_healing(90);
	return 1;
}
}
int ask_meat()
{
        if (!(this_player()->query_temp("fat_quest/ask")) || (int)this_player()->query_temp("fat_quest/ask")<2)
        write(
        "���ú�����ò��˵��: ���������о�Χ�壬����?\n");
        else
        {
        write(
        "����������ĳ����ᣬ��΢˼����һ�£�תͷ����˵��: \n"
        "�����춾��ѵ����⣬�ҿ��ܰﲻ��ʲ��æ���⼸���������Ƕ����ٳ�ȥ\n"
        "��������ɽկ֧����ȫ������Ӫҵ˰����Ӫ��ҵ����ǰ����Ǯׯ���Ǯ��\n"
        "��Ϣ��ά�֣������ά��һ����֧ƽ��ľ��档�����ʶ����ŵľ��ѣ���\n"
        "����û�о�����..........\n\n"
        "˵�꣬���������˳�˼\n\n");
        call_out("fish",15,this_player());
        }
        return 1;
}
int fish()
{        
        write(
        "������������������: ��? ��? �����б��˵�����?\n\n");
        call_out("fish1",5,this_player());
        return 1;
}
int fish1()
{
        write(
        "���û�����̧��ͷ��˵��: ��һ���취��Ӧ�ÿ��Խ���ʶ����鷳��\n"
        "������ɽկ���棬��һ���ǳ���ĺ���������ʢ��������Ϻ�������\n"
        "����������������Ӧ���ǲ�������⡣���ȥ����ʶ�����һЩ��\n"
        "Ϻ�����Կ�����춲������ȥ��ˮ����һ��������˳���ˣ�����˵\n"
        "�ҽ�����һЩ��Ϻȥ���ʶ������飬���������ԵĻ������������\n"
        "�ɡ�˵�꣬����΢Ц�������������̡�\n");
        this_player()->set_temp("fat_quest/fish",1);
        return 1;
       
}                