#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(17);
    set_name("Hua Rong","����");
    add("id",({"hua","rong"}) );
    set_short("����");
	set_long(@C_LONG
���С��㣬�����ˣ���������������壬ʹһ������������ͨ�񣬰ٲ���
�ĿǰΪ��ɽ�����������ȷ�ʹ���������Ⱥ�����ɽ���ԡ�
C_LONG
	);
    set("alignment",400);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "��" );
    set_perm_stat( "dex",30);
    set_perm_stat( "str",21);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",20);
    set_skill("blunt",90);	
    set_skill("dodge",100);
    set ("max_hp",470);
    set ("hit_points",470);
    set ("time_to_heal",3);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(25,15,25);
	set_natural_armor(40,22);
	set ("aim_difficulty",([ "weakest":20,"vascular":30]) );
	set("special_defense", (["magic":30,"none":10]) );
    set ("weight", 400);
    set( "inquiry", ([
             "hunt" :"@@ask_hunt1",
             "����" :"@@ask_hunt1",
             ]) );
    equip_armor(TARMOR"fur_hat");
    wield_weapon(TWEAPON"bow");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"beast_plate");
    equip_armor(TARMOR"darkgreen_cloak");
}
int ask_hunt1()
{
    command("sigh "+(string)this_player()->query("name"));
    call_out("ask_hunt2",5,this_player());
    return 1;
}
int ask_hunt2()
{
    write(@C_LONG
����˵��: ��������Ψһ���������֣������Դ��ϴΣ�����������
����ɽ��һ����ɫ�Ĵ����Ͻ��Ǹ�ɽ��֮�ᣬɽկ����Ҳ��׼�����ɽ
�����ˣ���ʵ�����ҵĹ���ͼ�����һ����������Ҳ���������
C_LONG);
    command("snort ");
    return 1;
}           