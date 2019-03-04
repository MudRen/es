#include "mudlib.h"
 
inherit MONSTER;
 
void create()
{
	
	::create();
	set_level(18);
	set_name( "Archmaster's Wife Hsiao", "��СС" );
	add ("id", ({ "wife","hsiao" }) );
	set_short( "��СС" );
	set_long(
"������ǰ�ľ��Ǵ��ʦ������ -- ��СС����������һ�����ò����һ����\n"
"��������֦���ȣ����������������һ��Ҳ�����������һ��Ҳʹ�˻�����\n"
"Ȼ��������ü��֮�У�ȴ������һ�ɵ������ǳ���˾��ú������ۡ�Ҳ��\\n"
"���������������θ����ʦ��ʶ�ġ�\n"
	);
    set( "gender", "female" );
    set( "race", "human" );
    set( "unit", "λ" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 17 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 23);
	set ("max_hp", 799);
	set ("hit_points", 799);
	set ("wealth", ([ "gold": 150 ]) );
	set_natural_weapon(20,10,25);
	set_natural_armor(99,36);
	set ("special_defense",(["all":33,"none":33,"monk":33,"scholar":33]));
	set("aim_difficulty",(["vascular":30,"weakest":30,"ganglion":30]) );
    set ("weight", 400);
    set_skill("dodge",90);
    set_skill("dagger",100);
    set_skill("anatomlogy",70);
    set("aiming_loc","weakest");
    equip_armor("/d/eastland/tomb/armors/cloth");
    equip_armor("/d/eastland/tomb/armors/armband1");
    wield_weapon("/d/eastland/tomb/weapons/dagger");
    set( "inquiry", ([
         "archmaster" : "@@ask_master" ,
         "master" : "@@ask_master",
         "nickname" : "@@ask_name" ,
         "jade" : "@@ask_jade",
         "box" : "@@ask_box"
           ]) );
}
 
void ask_box()
{       object obj;
        if (this_player()->query_temp("tombkey") == 1) {
        command("bonk "+(string)this_player()->query("name"));
        command("say ���Ӿ�������װ��������....��Ҫ�ʼ��ΰ���\n");
        command("gag "+(string)this_player()->query("name"));
        } else {
        command("smile "+(string)this_player()->query("name"));
        command("say ���Ӳ�������װ��������....��Ȼ����Ϊ�أ�\n");
        tell_object(this_player(), @ASK
 
��СС˳�ְ�����һ�ƣ���ԭ�����ӵĵ��µ�λ����һֻԿ�ף��������ƺ�û�з��ֵ���
 
��թ���������һ����ͷ��ע�⣬͵͵��Կ�׼���
 
ASK );
        obj=new("/d/eastland/tomb/item/key1");
        obj->move(this_player());
        this_player()->set_temp("tombkey",1);
        return;
        }
}
 
void ask_name()
{
        command("giggle");
        command("say ���С���� ����������\n");
        command("blush");
        return;
}
 
void ask_master()
{
	command("sigh");
	command("say ��Ҫ������.....\n");
	command("twiddle");
	return;
}
