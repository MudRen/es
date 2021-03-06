#include "../dony.h"

inherit MONSTER; 

void  create()
{
	::create();
	set_level(18);
	set_name( "japan fighter", "黑月" );
	add ("id", ({ "japan", "fighter" }) );
        set_short( "东瀛武士 黑月" );
	set("unit","位");
        set_long(@C_LONG
黑月身穿一袭黑色劲装, 全身上下只露出眼睛的部分而己。从他的眼睛里,你可以
看到一双类似野兽的凶狠目光,似乎要把你给吞了下腹。他的杀人的技巧是一流的
,只要被他盯上,那麽那个人不出三天就会死了,而且往往死状凄惨无比。他现在受
雇於某人, 似乎正在执行某件任务。 
C_LONG	
	);
        set("weight",680);
	set("alignment",-4000);
	set("wealth/gold",100);
	set_perm_stat("int", 23);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 30);
	set_perm_stat("kar",21);
	set("max_hp",550);
	set("hit_points",550);
	set_natural_weapon( 39, 15, 25 );
	set_natural_armor( 30,45 );
	set ("gender", "male");
	set ("race", "human");
	set_skill("parry",70);
	set_skill("dodge",80);
        set_skill("longblade",70);
	set_skill("anatomlogy",100);
        set("aiming_loc","weakest");
        set("special_defense", ([ 
              "divine": -20,"evil":30,"none":30]) );
        set("aim_difficulty",
              (["critical":80,"vascular":40,"ganglion":50,"weakest":80]) );
	wield_weapon(DWEAPON"katana");      
	equip_armor(DARMOR"japan_cloth");
        set( "inquiry", ([
              "chan":"@@ask_chan"
        ]) );
        set( "tactic_func", "my_tactic" );
}
void ask_chan( object asker )
{
   tell_object( asker ,
      "黑月说道:你是全副帮主派来的?那他有没有告诉你说下一步要做些什麽?\n");
   return ;   
} 
int accept_item(object me, object item)
{
      string name,my_name;
            
      name=(string)item->query("name");
      my_name=(string)me->query("name");
      
      if (name!="a white letter")
          return 0;
      
      if ( ( name=="a white letter" )&&( this_object()->query("be_asked") ) )
      {
         tell_object(me,
            "黑月说道:唉哟,不妙了,我把钥匙给错人了!!你快追!!\n");
         command("give a white letter to "+my_name);      
         return 1;
      }
      if ( ( item->query("master") ) != my_name ) {                               
         tell_object( me,
           "黑月说道:你这是打那儿的信件啊?\n");
         command("give a white letter to "+my_name);  
      } 
      else {
         tell_object( me,
           "黑月接过你的信件思考了一会儿。\n");
         item->remove();
         call_out("recover1",2,me);
         this_object()->set("be_asked",1);
         call_out("recover2",1800,this_object());
      }

}
void recover1( object obj )
{
     object ob1;
     ob1=new(DITEM"key.c");
     tell_object( obj ,
       "黑月说道:哦,原来是全副帮主说要你来拿钥匙的喔,拿去吧!不过不要搞\n"
       "         丢喔,这是我去弄来的。\n");
     ob1->move(obj);   
}
void recover2( object obj )
{
     obj->delete("be_asked"); 
}
int my_tactic()
{
    object env,me,victim;
    string my_name,vic_name;  
      
      victim=query_attacker();
      me = this_object();
      my_name=(string)me->query("c_name");
      vic_name=(string)victim->query("c_name");
      env = environment(me);
       
      if ( !victim ) return 0;
        
      switch( random(40) ) {
      case 1..3 : 
                victim->receive_special_damage("evil",40);
                tell_room(env,my_name+
                      "手拟星天弓要诀,化黑暗的波动为一把利箭射向"+vic_name+"的要穴!!\n\n",victim);             
                tell_object(victim,my_name+
                      "手拟星天弓要诀,化黑暗的波动为一把利箭射向你的要穴!!\n\n");
                report(this_object(),victim);
                return 1;
      case 4 :  
                victim->receive_damage(25);
                tell_room(env,my_name+
                       "从身上掏出一支十字飞镖射向"+vic_name+"的身上!!\n\n",victim);
                tell_object(victim,my_name+
                       "从身上掏出一支十字飞镖射到你身上!!\n\n");                       
                report(this_object(),victim);
                return 1;       
      case 5..6 :
                victim->receive_damage(38);
                tell_room(env,my_name+
                       "幻化成十个人形,从想不到的方位,给"+vic_name+"一个痛击!!\n\n",victim);
                tell_object(victim,my_name+
                       "幻化成十个人形,从你想不到的方位,给你一个痛击!!\n\n");
                report(this_object(),victim);
                return 1;  
      default :
                return 0;
      }
}
