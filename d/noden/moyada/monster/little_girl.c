#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(1);
	set_name( "little girl", "СŮ��" );
	add( "id", ({ "girl", }) );
	set_short( "СŮ��" );
	set_long( @C_LONG
������ʮ�ֿɰ���СŮ����һֱ������΢Ц��
C_LONG
	);
	set_perm_stat( "dex", 5 );
	set_perm_stat( "str", 5 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 5 );
	set_perm_stat( "piety", 5);
	set_perm_stat( "karma", 5);
   set( "race", "human" );
	set ("gender", "female");
	set ("unit", "��" );
	set_natural_weapon( 10, 5, 10 );
	set_natural_armor( 10, 10 );
	set_skill("dodge",100);
    set("weight", 300);
    set("exp_reward",1);
    set("immortal" ,1);
}

void change( object what, object player )
{
    object ob;
    ob = new( MOYADA"monster/daemon" );
    ob->move( environment(what) );
    tell_object( player,@ALONG
     
СŮ�����һ��: �ɶ�! ������ʶ���ˣ�ֻ���ֳ��ҵ�����Ŀ!
СŮ��ͻȻҡ��һ���һֻ���µĶ�ħ��
  ��ħ���һ��: ������!

ALONG
      );       
    player->set_explore("noden#6");
    ob->kill_ob(player);
    player->kill_ob(ob);
    what->remove();
}
