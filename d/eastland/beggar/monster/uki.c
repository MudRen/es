#include "/d/eastland/beggar/dony.h"

#define MAX_HP(x)   (int)x->query("max_hp")
#define HP(x)       (int)x->query("hit_points")
#define NAME(x)     (string)x->query("name") 
#define BANDAGED(x)  x->query_temp("bandaged")
        
inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "Doctor Uki", "小雪子" );
    add( "id",({"doctor","uki"}) );
    set_short( "一代神医 小雪子");
    set_long(@LONG
小雪子看起约莫二十四、五岁的年纪,亭亭玉立,身材苗窕,顾盼间颇有勾魂夺魄之
态。同时,她也是这里唯一的行医者,虽然她年纪不大,颇得医仙的真传,所以,凡有
受伤或者遭逢疾病的, 都会来向她请教 ( help )。渐渐地,她的名气传了开来,不
少年轻公子哥儿都来追求她,想一亲芳泽,可是落花无情,谁也不知道她心里在想些
什麽。 
LONG
            );
    set("unit","位");
    set("race","human");      
    set("class","healer");
    set("age",18);
    set("gender","female" );
    set("alignment",1000);
    set("weight",600);
    set("wealth/gold",2);
    set_temp("be_joke",100);
    set_perm_stat("str",19);
    set_perm_stat("dex",26);
    set_perm_stat("kar",30);
    set_perm_stat("int",28);
    set_perm_stat("pie",23);
    set("hit_points",550);
    set("max_hp",550);
    set("max_fp",300);
    set_natural_armor(20,44);
    set_natural_weapon(21,0,0);
    set_skill("dagger",80);
    set_skill( "bandage",90);
    set_skill("anatomlogy",100);
    set_skill("dodge",75);
    set_skill("parry",70);
    set("stun_difficulty",50);                                              
    set("special_defense", ([ "all": 40,"none":30,"monk":30,"scholar":30]) );
    set("aim_difficulty",
    (["critical":50,"vascular":70,"ganglion":70,"weakest":30]) );
    set("stun_difficulty",90);
    wield_weapon(DWEAPON"needle");
    equip_armor(DARMOR"uki_cloth");
    equip_armor(DARMOR"uki_amulet");
    set( "inquiry", ([
              "help":"@@ask_help",
           "bandage":"@@ask_bandage",
               "hau":"@@ask_hau",
               "war":"@@ask_war" 
    ]) );                       
    set( "tactic_func", "my_tactic" );
}        

void init()
{ 
  ::init();
  add_action("do_angry","slap");
  add_action("do_angry","kick");
  add_action("do_angry","kiss");
  add_action("do_angry","flog");
  add_action("do_angry","hold");
  add_action("do_angry","lkiss");
  add_action("do_angry","smirk");
  add_action("do_angry","excite");
  add_action("do_angry","puke");
  add_action("do_angry","snort");
  add_action("do_angry","bite");
  add_action("do_angry","lick");
  add_action("do_angry","bark");
  add_action("do_angry","fart");
  add_action("do_angry","spit");
}

void do_angry(string arg)
{
   call_out("do_kick",4,arg);
}

void do_kick(string arg)
{
    if (arg=="uki"){
       tell_object( this_player(),
          "\n小雪子愤怨地向你说道:你这无礼的小贼去死吧 !!\n\n");
       tell_room( environment(this_object()),
          "\n小雪子似乎对"+this_player()->query("c_name")+
          "很不爽并对他采取攻击!!\n\n",this_player());
       this_object()->kill_ob(this_player());
       this_player()->block_attack(6);
       this_player()->set_temp("msg_stop_attack","(  你因为太无礼而被拦住动弹不得 !!  )\n");
       return ;
    }
}
void ask_help( object asker )
{
    tell_object( asker ,
         "小雪子说道:哦,你要求帮助?\n"
         "小雪子语气停顿并且深深地叹了一口气 ...\n"   
         "小雪子继续说道:如果先师还在,那就可以帮你更多,可惜.....\n"
         "小雪子说道:几年前帮中发生内乱,我师父不幸战死,只留下一门包扎技能,\n"
         "           如果你能给我一些绷带的话...............\n");
}

void ask_bandage( object asker )
{
     object ob1;
     
     if ( !asker->debit("gold", 6) ) {
        tell_object( asker, 
          "小雪子说道:我帮你包扎总需要拿点工本费吧!\n");
        return ;     
     }
     if ( asker==query_attacker() ) {
        tell_object( asker , 
          "小雪子怒道:哼,你别笨得可以了,我怎麽可能帮敌人包扎咩?\n");
        return ;
     }
     if( !present( "bandage",this_object() ) ) {
        tell_object( asker , "小雪子说道:唉,我身上没有任何绷带可以帮你。\n");
        return ;
     }       
     if ( HP(asker)==MAX_HP(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "小雪子说道:咦,你好好的吗。\n");
        return ;     
     }
     if ( BANDAGED(asker) ) {
        command( "look "+NAME(asker) );
        tell_object( asker , "小雪子说道:哦,你似乎被包扎过了...\n");
        return ;    
     }
     command( "look "+NAME(asker) );
     command( "bandage "+NAME(asker) );
     command( "smile "+NAME(asker) );
     tell_object( asker, 
        "你很感激地想亲 ( kiss ) 小雪子一下做为报答,但是想想又觉得不妥。\n");
     return ;                 
}

void ask_hau( object asker )
{
    if ( asker->query_temp("keeper_finish1") ) {
       tell_object( asker ,
          "小雪子说道:哦,你问帐房霍先生的内人?\n"
          "你向小雪子报告所发生的事。\n"
          "小雪子思考了一会儿。\n" 
              );
       asker->set_temp("uki_asked",1);
       call_out("recover1",10,asker);
    } else 
       tell_object( asker,
          "小雪子说道:我不知道。\n");
}

void recover1( object obj)
{
    tell_object( obj ,
       "小雪子说道:唉,我也不知道为什麽会这样,我只知道熊蛇丸可以起死回生。\n"
       "           嗯,你去请教 祠堂 老院长 吧,他活得久可能知道些什麽。\n"         
       "\n你心里骂小雪子是个大庸医。\n"
                );
}
void ask_war()
{
write(@C_LONG
小雪子说道:记得在我很小的时候,这里发生了一件惨事,唉,我师父就在那里时候阵亡。
           唉唉.......
小雪子似乎不太想说。           
C_LONG
    );
}
int my_tactic()
{
     object victim;
     int select;     
     
     if (!(victim= query_attacker())) return 0;
     if ( victim->query("conditions/herb_apply") ) {
        tell_object(victim,
          "小雪子狂笑道:哈哈哈哈哈,在我面前竟敢涂药药?别傻了!!!\n");
        victim->delete("conditions/herb_apply"); 
     }      
     select=random(10);
     if ( select > 4 ) set("aiming_loc","critical");
     else if ( select > 1 ) set("aiming_loc","weakest");
     else if ( select > 0 ) {
        if ( victim->query("conditions/bleeding") ) set("aiming_loc","weakest");
        else set("aiming_loc","vascular");
     }
     return 0;          
}                  