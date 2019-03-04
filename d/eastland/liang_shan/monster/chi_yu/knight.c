#include <mudlib.h>

inherit "/d/eastland/liang_shan/monster/chi_yu_group";

void create()
{

	::create();
	set_level(17);
	set_name( "snaky warrior", "����սʿ" );
	add( "id", ({ "warrior" }) );
	set_short( "����սʿ" );
	set_long(@C_LONG
������ʵ����˵��û�нŵ������ˣ���û������������ǿ׳
����ȴ��Զ������ǵ��ǻۡ�������ˣ������ϸ�ѵ������
�˻��ǿ��Գ�Ϊ���͵�սʿ�������ܹ�����ʹ����಻ͬ��
ս����
C_LONG	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -500 );
	set_natural_weapon(20,15,15);
	set_natural_armor(20,20);
	set( "special_defense", ([ "all": 20,"none":10 ]) );
        
        set("aim_difficulty",
        ([ "critical":25, "vascular":20, "weakest":35, "ganglion":5 ]));

	set("chi_yu_group",1);
	set( "wealth/silver", 250 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "dex", 24 );
	set( "aiming_loc", "weakest" );
	set_skill( "anatomlogy",60 );
	set_skill( "longblade", 90 );
	set_skill( "parry", 80 );
	set_skill( "block",85 );
	set("tactic","berserk");
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"[1m����սʿ���: ��ȴ����Ϳ�����ˣ���ҿ��������Ǭ����[0m\n",
		"[1m����սʿ˵��: ������������Ҫ����ν�ĵֿ���[0m\n",
		"[1m����սʿ�ȵ�: ���ӻ������߸����������ǵ�Ӣ�۶�����ȥ�ˣ�[0m\n"
	}) );

        wield_weapon( "/d/deathland/weapon/sword03" );
//        equip_armor( "/d/noden/drow/arm/a18" );
  //      equip_armor( "/d/noden/drow/arm/a10" );
    //    equip_armor( "/d/noden/drow/arm/a14" );
}

int my_tactic()
{
	object victim;
        
        if ( !victim = query_attacker()) return 0;
	
	if( random(20)<3 ) {
        tell_object(victim,set_color( "˵ʱ�٣���ʱ�죬����սʿ����������β����������ɨȥ����һ��\n"
        "��С�ģ��������ڵ��ϡ�\n","HIM",victim));
        tell_room(environment(this_object()),set_color("˵ʱ�٣���ʱ�죬����սʿ����������β����"
        +victim->query("c_name")+"������ɨȥ���������ڵء�\n","HIM",victim),victim);
        victim->block_attack(3);
        victim->set_temp("msg_stop_attack", "\n�� ������ˤ���ڵ��޷����� ��\n\n");
        victim->receive_damage(5);
        return 1;
	} else return 0;
}

void relay_message(string class, string str)
{
        int i,hitp,hp1,hp2;
        string name,direction,tmp,guild;
        object victim,mob,env,*who,bandage;
        mixed bandaged,bleed;
        ::relay_message(class,str);
        
        
        if( !str || str == "" ) return;
        if( sscanf(str,"%s(%s)���˹�����", tmp,name)==2 ) {
        name = lower_case(name);
        victim = present(name, environment(this_object()));
        if( !victim || victim->query("npc") || victim->query("no_attack")) return ;
        
        if( victim->query_level() > 5 && !victim->query("ghost") && victim->query("alignment") >100 ) {  
        
        if( !pointerp(attackers) || member_array(victim, attackers)==-1 ) {
        
        tell_object(victim,query("c_name")+"�е� : ͨͨȥ���ɣ�ͬʱ���������������������....\n");
         kill_ob(victim);
         } } }
        if( sscanf(str,"%s��%s�뿪��", tmp,direction)==2) {
        if ( query_attacker() ) return ;
        hp1 = query("max_hp")/2;
        hitp = query("hit_points");
        if ( bleed = query("conditions/bleeding") || hitp < hp1  )        
        tell_room(environment(this_object()),
        "����սʿ(warrior)˵��: �����Ѿ������ˣ������������ư�.....\n",this_object());
        return ;
        }  
}        
 