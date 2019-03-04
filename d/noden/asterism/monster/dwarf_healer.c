#include "../asterism.h"

inherit MONSTER;
void create()
{
	::create();
	seteuid(getuid());
	set_level(16);
	set_name( "dwarf healer", "����ҽ��" );
	add("id",({"healer","dwarf"}) );
   set_short( "����ҽ��" );
	set_long(
		"һ������İ���ҽ��.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 300 );
	set( "time_to_heal", 5 );
	set_natural_armor( 66, 30 );
	set_natural_weapon( 21 , 10 , 14 );
	set("max_hp",500 );
	set("hit_points",500 );
	set("max_sp",500 ) ;
	set("spell_points",500 ) ;
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 19 );
	set_perm_stat( "int", 28 );
	set_skill( "parry",80 );
	set( "wealth/gold", 3 );
	set( "special_defense", ([ "all": 22 ]) );
	set_skill("anatomlogy",100);
	set_skill("dodge",80 );
	set_skill("dagger",80 );
	set_skill("concentrate",80 );
        set_skill("white-magic",80 );
        set_skill("defend",80);
        set("aiming_loc","vascular");
	set("spells/heal",3 ) ;
	set( "aim_difficulty",(["critical":100,"weakest":60
	                       ,"vascular":60,"ganglion":60]) );
	wield_weapon(WEAPONS"scalpel");
	equip_armor(ARMORS"ring02");
	equip_armor(ARMORS"gloves02");
	set("echo_asterism",0);
        set( "tactic_func", "cast_help" ); 

        set("inquiry" , ([ 
                      "����" : "@@astrquest" ,
                      "catalyst" : "@@astrquest"
                   ]) ) ;
                                                                                           
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_asterism") ) return 1;
    return 0;
}

int cast_help()
{ 
    object victim, *guard;
    int i;
    
    victim = query_attacker();
    if( !victim ) return 0;
    if ( nullp(environment(this_object())) ) return 0;
    guard = filter_array(all_inventory(environment(this_object())),
            "is_a_guard",this_object());
    for( i=0; i<sizeof(guard); i++ ) 
     {
     if ( !guard[i]->query_attacker() ) {
      tell_room( environment(this_object()), 
        guard[i]->query("c_name")+"��: ⷰ���,���Ұ�����һ��ѵ��˸��߰�!\n"
          ,guard[i]
      );
      guard[i]->kill_ob(victim);
      }
     }
    return 0;
}

int is_a_soldier( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("astr_soldier") ) return 1;
    return 0;
}

void relay_message(string class1 , string msg)
{
    int i ;
    object *soldier ;
    string a;
    
    if ( sscanf(msg,"����ʿ��˵����heal me please%s",a) != 1) {
    	::relay_message( class1, msg );
    	return ;
    }
	if ( nullp(environment(this_object()) )) return ;
    soldier = filter_array(all_inventory(environment(this_object())),
              "is_a_soldier",this_object());
  
        tell_room(environment(this_object()),
           "����ҽ��˵��:�õģ������ϰ������ˡ�\n"
           "����ʿ��������ʱ����һ���׹�,ͬʱʿ�����ϵ��˽�����ʧ��\n"
           , this_object() ) ;
        for( i=0; i<sizeof(soldier); i++ ) 
             soldier[i]->receive_healing(40) ;
        set("echo_asterism",1) ;           
    return ;
}

void astrquest(object ob)
{
   int questflag,stepflag ;
   
   questflag = ob->query("astr/questa")  ;
   stepflag =  ob->query_temp("astr/quest1")  ;
   if( !questflag || questflag!=2 || !stepflag || stepflag <1 )
     {
       tell_room(environment(),
                 "����ҽ��ҡҡͷ˵:�Ҳ�֪����\n" 
                 ,this_object()  ) ;
       return ;
      }

   write(
         "����ҽ������һ������˵��: �Һ�������������һ��������ŷ�𰲳���,\n"
         "    ���������������ҵ��Ǹ�������,ֻ�ǵ��Ǹ�������'�Ų��޻�'��\n"
         "    ������ǻ���,�ҾͲ�����ˡ�\n"
         );

   
   this_player()->set_temp("astr/quest1",2) ;
   return ;  
}

