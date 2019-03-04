#include "../takeda.h"
#include <stats.h>
#include <conditions.h>

inherit MONSTER ;
void create()
{
	::create();
	set_level(8);
        set_name( "Huan Fu Duan", "�ʸ���" );
        set_short( "�ʸ���" );
	add( "id", ({ "doctor","healer","huan","fu","duan" }) );
	set_long(
@C_LONG
�㿴��һ���������ص������ˣ�������ɫ�ĺ��룬��������������ҽ�ʸ��ˣ�
���ݸ��ˣ�������ײ���������������֪��һ��ͷ�ں��֢����ҩ���룬
�޲�Ȭ�ɣ���Ϊ��ɽ������ƥ��ҽ�������������ĸ�ҵ�������䣬˵����
���������ҵ�һƥ����
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
	set_perm_stat("str",10);
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "anatomlogy", 40 );
	set("defense_type","dodge");
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 120 );
        set( "hit_points", 120 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "evil": 30,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "heal": "@@ask_heal",
                "diet": "@@ask_diet"
	
        ]) );
        wield_weapon( TWEAPON"poblade" );
        equip_armor( TARMOR"small_cloth" );
        equip_armor( TARMOR"simple_boots");
}
    
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), 
        "�ʸ���ŭ��: ���ɵļһ� !! ���һ�����ҽ�� !! ���������ѵ�� ! \n" ,
        this_object() );
        (CONDITION_PREFIX +"simple_poison")->apply_effect(this_player(),8,5);
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"�ʸ���˵��: ���������ڵģ�����������? \n" ,
	this_object() );
	return 1;
	}
	
	num=(hpmax-hp)*6;
       if( !this_player()->debit("gold", num) )
        return notify_fail( 
	"�ʸ���ҡҡͷ��������Ǯ��̸����\n");

	tell_room( environment(), 
	"�ʸ���Ц��������..����Ǯ�ķ��ϣ������ҿ����ɣ�˵���ó���һЩ��Ե����ǿ��\n"+
	"����£�һ��θ֮�ᣬ����˺ö��ˡ��ʸ���˵�����˸����Ȼû�в�ͬ��\n" ,
	this_object() );
	this_player()->set("hit_points",hpmax);
	return 1;

}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3)
write(
"�ʸ���̾��: ��һ���������ĵ��ˣ�������ʲ������??\n");
else {
write(
"\n�ʸ����������ͷ˵��: ����������������ҩ�����ǣ���������ܸ��˳���?\n"
"�ǰ���ȫ�������İ�? ����ϲ�����˿���Ц�ˣ�Ҳ��Ϊ��������Ψһ�����ð�С\n"
"�ۣ��Ż�����ַ����ܵ�������ȥ���衣˵�꣬�ʸ��˺����Ȼ����ʲ������\n");
command("hmm ");
call_out("ask_sister1",10,this_player());
return 1;
}
}
int ask_sister1()
{
write(
"�ʸ���һ�Ĵ��ȣ�˵��: �������������?? ����һ�����ˣ�ǰһ�����������ʱ��\n"
"�����ᵽ����������һ����Ч���ʲ裬������ǰ�С��������?������Ƣ���ֵֹģ�\n"
"����Ӧ����Ҳ��\�����ȥ�Ұ���ȫ�������......\n");
return 1;
}