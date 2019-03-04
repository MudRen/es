#include "../almuhara.h"
 
inherit MONSTER;
 
void create ()
{
	::create();
	seteuid( getuid() );
        set_level(18);
	set_name( "Sky Guilt", "�� ���� ��" );
	add ("id", ({ "sword","sky guilt","sky","guilt" }) );
	set_short( "�� ���� ��" );
	set_long( 
@C_LONG
���ǡ� ���� ����һֻ���Ϲ��������ȡ��������֮�������û��ɵ����ޡ�����
����ɢ������а�������㲻��������
C_LONG
	);
	set( "alignment", -5000 );
        set( "unit", "��" );
        set_perm_stat( "dex", 23 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "int", 26 );
        set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 10 );
        set_perm_stat( "karma", 20 );
	set ("chat_chance", 5);
        set ("max_hp", 1200);
        set ("hit_points", 1200);
	set ("killer", 1);
	set("stun_difficulty/ma",40) ;
        set("aim_difficulty",(["critical":80,"weakest":60,
                               "vascular":40,"ganglion":60 ])) ;
        set_natural_weapon( 70, 40, 70 );
        set_natural_armor( 100, 30 );
    set ("weight", 150);
    set ("exp_reward", 27767 );
    set ("special_defense", 
         ([ "all":50, "none":40, "fire":20, "cold":30 ]) );
    set_skill("tactic",90);
    set_skill("dodge",90);
    set_skill("parry",90);
    set("tactic","assault");
    set_c_verbs( ({ "%sֱ��%s", "%s��ն%s","%sб��%s"}) );
    set_c_limbs( ({ "����", "����","����" }) );
    set( "alt_corpse", WEAPONS"/d_sky_guilt" );
    set( "c_death_msg", "%s����һ�������ı���������ԭ�Ρ�\n");
    set( "att_chat_output", ({
		"�������Ц˵��: ���ҳ�������������ڵ���!!\n",
	        "��������ؿ����㡣\n", }) );
}
 
void die()
{
	object ob;
	
	ob = query("last_attacker");
	ob->set_temp("GUILT",1);
        if ((string)ob->query("class")=="scholar") {
          tell_object(ob,set_color(
 "ͻȻ�������Ľ�������һ���Σ�лл�����а����������ȥ����������������\n�Ľ��꣬�������Ĺ�ϵ���Ҷ����ܺúõ��������������ܶ���֮��������Ҫ�ҵİ�æ��\n�벻Ҫ������\n"
          ,"HIW"));
          ob->set("demand/sword",2);
        }
	::die();
}
