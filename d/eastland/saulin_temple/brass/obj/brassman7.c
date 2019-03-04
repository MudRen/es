#include "../almuhara.h"
#include "conditions.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(15);
        set_name( "brassman", "ͭ��" );
        add ("id", ({ "brass","monk" }) );
        set_short( "ͭ��" );
        set("unit","λ");
        set_long(
@C_LONG
һ�����������ͭ�ˡ�
C_LONG
        );
        set("hit",0);
        set("alignment",0);
        set("gender", "netural");
        set("class", "monk");
        set("max_hp", 5000);
        set("max_fp", 500);
        set("hit_points", 5000);
        set("force_points", 500);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 25);
        set_perm_stat("pie", 21);
        set_perm_stat("kar", 22);
        set_perm_stat("int", 20);
        set("unbleeding",1);
        set("killer",1);
        set("c_killer_msg","ͻȻ���㿴��ͭ��ҡҡ�λε����㿿�˹��� !!");
        set_natural_weapon( 50, 22, 32 );
	set_natural_armor( 40, 5 );
        set_skill("dodge", 100);
        set("attack_skill","monk/fist/long_fist");
	set("tactic_func","my_tactic");
	HEAL_HP->remove_effect(this_object());	
}

int my_tactic()
{
	object ob,who,*obj,ob1;
	int i,weapon,j;
	
	ob = this_object();
	obj = all_inventory(environment(ob));
		i = sizeof(obj);
	while(i--) {
		if( userp(obj[i]) ) break; }
	who = obj[i];
//	if( wizardp(who) ) return 0;
	if(((int)who->query("hit_points")*100 / (int)who->query("max_hp")) < 25) {
		tell_object( who,
			"ͻȻ���������޺���ǽ�а����߳�������̧�˳�ȥ��\n" );
		ob1=find_object_or_load("/d/eastland/saulin_temple/entrance");
		tell_room(ob1,
			sprintf("�㿴�����������޺���%s��̧��һ��̧�˳�����\n",
				who->query("c_name") ) );
		who->add("monk_score",-100);
		who->move_player(ob1,"SNEAK");
		ob1->set("enter",0);
		return 1; }	
        if( (int)ob->query("force_points") < 100 ) 
        	ob->add("force_points",500);
        	
	obj = all_inventory(who);
		i = sizeof(obj);
	while(i--) {
		if( obj[i]->query("wielded") ) {
			weapon = 1;
			break; } }
	if( !who->query("attack_skill") && !weapon ) {
		weapon = 0;
		ob->add("hit",1); }
	else weapon = 0; 
        if( ob->query("hit") == 14 )
            die();
            	
		return 0;
}

void die()
{
	object killer, *obj;
	int i,j;
	
	this_object()->init_attack();
	obj = all_inventory(environment());
	i = sizeof(obj);
	j = 0;
	while(i--) {
		if( (string)obj[i]->query("c_name") == "ͭ��" ) 
	           j++;
	        if( !obj[i]->query("npc") )
	           killer = obj[i];
	           } 

	if ( killer ) {
		tell_object(killer,set_color("һ��������ᣬͭ�˲����� !!\n","HIG") );
		if( j <= 1 ) 
			killer->set_temp("be_k",1);
	}
	call_out("remove",0);
}

