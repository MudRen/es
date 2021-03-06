#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "drynurse", "奶妈" );
	add("id",({"drynurse","dwarf"}) );
   set_short( "矮人奶妈" );
	set_long(
		"从小看著矮人王长大的奶妈。因为和皇家的关系如此密切，所以\n"
		"艾斯特律恩的居民早视她为矮人皇室成员之一了。\n"
	);
	set( "gender", "female" );
	set( "race", "dwarf" );
	set( "alignment", 450 );
	set( "time_to_heal", 7 );
	set_natural_armor( 26, 7 );
	set_natural_weapon( 17 , 8 , 14 );
	set("max_hp",150);
	set("hit_points",150);
	set_perm_stat( "str", 10 );
        set_perm_stat( "dex", 10 );
	set_skill( "dodge",20 );
	set( "wealth/gold", 10 );
	set( "special_defense", ([ "all": 12 ]) );
        set( "have_call_help",0 ) ;
        set( "tactic_func", "cast_help" ); 
        set( "chat_chance", 25 );
        set( "chat_output", ({
                  "矮人奶妈说道:小阿莱特斯喜欢乱跑,真是令人担心。\n",
                  "矮人奶妈说道:真是的，小阿莱特斯不知道又跑到那去玩了。\n"
             }) ) ;
}

int is_a_guard(object ob)
{
    if( ob->query_attacker()) return 0 ;
    if( ob->query("echo_asterism") ) return 1;
    return 0;
}

int cast_help()
{ 
    object victim, *guard, *guarda, mob;
    int i,j,no,no1;
    
    victim = query_attacker();
    j=(int)this_object()->query("have_call_help");
    
    if( !victim ) return 0;
    
    guarda = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    no = sizeof(guarda) ;

    if(no !=0)
      {
        for( i=0; i<no; i++ )
           {
              tell_room( environment(this_object()),
             guarda[i]->query("c_name")+"喝道: 矮人族的敌人，以血赎罪吧 !!\n"
                ,guarda[i]  );
       
               guarda[i]->kill_ob(victim);
             }
         return 0;
       }
   
    if( j < 2)
      {
        tell_room( environment(this_object()),
                 "矮人奶妈大喊 : 救命啊 !! 杀人了 !!\n",
                 this_object() ) ;
            
        this_object()->set("have_call_help",j+1) ;  

        if(random(4)>0) return 0;
        tell_room( environment(this_object()),
              "你看到有两道人影从楼梯上迅速地跑了下来，并朝你冲了过来。\n",
                  this_object() ) ;
        
        mob = new(MOB"dwarf_guard02");
        mob->move(environment(this_object())) ; 
        mob = new(MOB"dwarf_guard02");      
        mob->move(environment(this_object())) ;
        set("have_call_help",2) ;
        guard = filter_array( all_inventory(environment(this_object())),
                          "is_a_guard", this_object() );
        no1 = sizeof(guard) ;
                   
        for( i=0; i<no1; i++ )
           {
                 tell_room( environment(this_object()), 
            guard[i]->query("c_name")+"喝道: 矮人族的敌人，以血赎罪吧 !!\n"
                ,guard[i]  );
       
              guard[i]->kill_ob(victim);
             }

      } 
//  this line below is  2 thing. 1. is check if have guard at side 
//                               2. is made random to call guard for help
//                                  
//    command("say no is" +no+ ",no1 is "+no1+",i is "+i+".\n");
    return 0;
}

