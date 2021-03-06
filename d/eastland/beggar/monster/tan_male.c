#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "sun male", "阳公公" );
	add("id",({"sun","male"}) );
        set_short( "大别山碧云洞 阳公公" );
	set_long(@C_LONG
阳公公约莫六、七十岁年纪,自二十年前看破世事就与阴婆婆稳居在大别山碧云洞
一直未涉世,因丐帮的邀请特地赶来参加丐帮『祭祖大典』。近年来新得极北玄玉
和玉火蟾蜍, 合成了灵验无比的伤药 ( herb ), 或许你可以向他要要看是否他会
给你一些。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 33);
	set("max_hp",460);
	set("hit_points",460);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",20 );
	set_perm_stat( "int",25 );
	set_skill( "parry",30 );
	set_skill( "dodge",70 );
	set( "wealth/silver",1);
	set( "special_defense", ([ "all": 40,"none":40 ]) );
	set( "aim_difficulty",(["critical":100,"vascular":40,"weakest":40]) );
	set("couple",1);
        set_c_verbs( ({ "%s使出『挨打不还手』第一招, 只手欺向%s。",
                        "%s虚晃一下『挨打不还手』第二招, 脸朝向%s准备被打。",
                        "%s吼叫一声,『挨打不还手』最强一式急打自己脸颊然後向%s砍了过去。"
                      }) ); 
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                 "阳公公说道:来人啊,救命啊,欺负老弱妇孺～ \n"
        }) );
        equip_armor(DARMOR"tan_ring");
        set("inquiry", ([
             "herb":"@@ask_herb"
        ]) );
        set( "tactic_func", "my_attack" );
} 
void ask_herb(object asker)
{
write(@C_LONG
阳公公说道:本来我在一处极热的地方捕获到一只玉火蟾蜍。但是,这几天又失落了,
           你能帮我找回来吗?
C_LONG
      );
}
int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}
int accept_item(object me,object item)
{
    string name;
    name=item->query("name");
    if ((name!="fire toad")&&(name!="box")){
        tell_object(me,this_object()->query("c_name")+
              "说道:你给我这个东西干嘛啊?\n");
        item->move(me) ;
        return 1;
    }
    if (name=="fire toad"){
       tell_object(me,this_object()->query("c_name")+
              "感激地说道:谢谢你帮我找回来"+item->query("c_name")+
              "请你等一下,我做一下药～～\n"); 
       item->remove();
       call_out("recover",2,me);      
       return 1;
    }  
    if ( item->query("charge_times")<1){
       tell_object(me,this_object()->query("c_name")+
            "说道:唉,你的小盒子太旧了～～\n");
       tell_object(me,this_object()->query("c_name")+
            "说著说著把你给他的小盒子拿丢掉!!\n");
       item->remove();
       return 1;    
    }
    if (me->query("wealth/silver")<1500){
       tell_object(me,this_object()->query("c_name")+
              "说道:想续杯,可以,请凄足一千五百大洋～～\n");
       command("give box to "+me->query("name"));
       return 1;
    }
    me->add("wealth/silver",-1500); 
    item->set("times",10);
    item->add("charge_times",-1);
    tell_object(me,this_object()->query("c_name")+
              "说道:好了,你的小盒子又装著满满的药～～\n"); 
    command("give box to "+me->query("name"));
    return 1;
}
void recover(object obj)
{
   object bonus;
   bonus=new(DITEM"box.c");
   bonus->move(this_object());
   tell_object(obj,this_object()->query("c_name")+
        "说道:嗯,我做的治伤灵药太多了,我把它放在小盒子里分你一些吧。\n");
   command("give box to "+obj->query("name"));
}
int my_attack()
{ 
    object victim,*env,*couples;
    int i;
    
    victim = query_attacker();
    if( !victim ) return 0;

    env=all_inventory(environment(this_object()));
    couples = filter_array( env,"can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), couples[i]->query("c_name")+
           "说道:想找我们过招,你们配吗?\n",couples[i]);
        couples[i]->kill_ob(victim);
    }

    if  ( random(12)>1 )  return 0;
    else{
       tell_room( environment(this_object()),
           "阳公公迅速地从怀中取出一只小盒,打开盒子,伸指沾些药膏涂在伤口处!\n");
       for ( i=0;i<sizeof(env);i++) 
          if ( env[i]->query("couple") )      
            env[i]->receive_healing(20);  
       return 1;
   }      
}


