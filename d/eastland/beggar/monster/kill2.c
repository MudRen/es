#include "../dony.h"
#include <daemons.h>
inherit MONSTER;
void create ()
{
	::create();
	seteuid( getuid() );
	set_level(19);
	set_name( "God longsword","���ɽ�[����״̬]" );
	add ("id", ({ "god","longsword" }) );
	set_short( set_color("���ɽ�[����״̬]","HIC") );
	set_long( @LONG
���ɽ���Ϊͨ���������������������Ŀڱ���֮һ���˽���������, ���ס���,
����һ��,�δ������������,Ҳ���ӵô��ѡ� ��������,�޴˱���:����ͭ������
�Ǹ�,��������ɽ�²ء� ���������ߵ���,����ˮ����â? ������,¾����,����
��������;���ɱ仯������,��������ѪȾ�ѡ���
LONG
	);
        set( "race", "undead" );
	set( "class", "knight" );
	set( "alignment", -3000 );
        set( "unit", "��" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 20 );
	set("max_hp", 1200);
	set("hit_points", 1200);
        set_temp("be_joke",10);
	set("persuing", 1);
        set("unbleeding",1);
        set("couple",1);
	set("aim_difficulty", ([ "critical" : 30, ]) );
        set_natural_weapon( 40, 29, 33 );
	set_natural_armor( 110, 20 );
        set("stun_difficulty",50);
        set ("weight", 150);
        set ("special_defense", 
           ([ "all":70, "none" : 70 ]) );
        set_skill("dodge",85);
        set_skill("defend",100);
        set_c_verbs( ({ 
              "%s���������ͻ�ݷ���������֮��,%s�ƺ���ɨ��",
              "%s��һ��ȦȦȻ���ֱ�����͵���%s�����˹�ȥ,������������",
              "%s��������һ����âֱ��%s"}) );
        set_c_limbs( ({ "����", "����", "����", }) );
        set( "tactic_func", "my_tactic" );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
         return 0;
}
int my_tactic()
{
   object *couples,victim;
   int i;
   if (!victim= query_attacker()) return 0;

   couples = filter_array( all_inventory(environment(this_object())),
       "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) 
        couples[i]->kill_ob(victim);
   if ( victim->query("npc") ) {
       tell_room( environment(this_object()),
           this_object()->query("c_name")+"��"+victim->query("c_name")+
           "���븹��....\n");
       this_object()->receive_healing(500);
       victim->remove();
   }
   return 0;
}
void die()
{
    object *all,obj;
    obj=this_object()->query("master");
    all=obj->query_temp("party_members");
    all=all-({ this_object() });
    obj->set_temp("party_members",all);
    delete_embattle_effect(this_object());
    set("alt_corpse",DWEAPON"kill2"); 
    set( "c_death_msg","%s���������Ϊһ����ͨ������....\n\n");
    ::die();
}