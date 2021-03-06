#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit "/d/eastland/liang_shan/monster/chi_yu_group";

void init()
{
   ::init();
   chi_yu_group::init();
}
void create()
{
	object ob1, ob2;

	::create();
	set_level(15);
	set_name( "snaky shaman", "蛇人巫医" );
	add( "id", ({ "healer", "shaman" }) );
	set_short( "蛇人巫医" );
	set_long(
		"蛇人其实可以说是没有脚的蜥蜴人，虽没有蜥蜴人那麽强壮\n"
		"但是却有远高於他们的智慧。蛇人巫医能够利用它所学的医术\n"
	        "和绿魔法以帮助需要帮助的队友。\n"
	);
	set("chi_yu_group",1);
	set( "unit", "名" );
	set( "race", "monster" );
	set( "gender", "female" );
	set( "alignment", -200 );
	set( "special_defense", ([ "all": 30,"none":20 ]) );
        set("aim_difficulty",
        ([ "critical":30, "vascular":40, "weakest":35, "ganglion":5 ]));

	set_natural_armor( 20, 25 );
	set_natural_weapon( 30, 25, 10 );
	set( "wealth/silver", 800 );
	set( "tactic_func", "my_tactic" );
	set_perm_stat( "str", 17 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "kar", 22 );
	set_skill( "blunt", 70 );
	set_skill( "bandage", 80 );
	set_skill( "dodge", 80 );
	set_skill( "anatomlogy", 80 );
	set_temp( "aiming_loc", "ganglion" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"[1m蛇人巫医说道: 你们还是放弃吧，伟大的蚩尤大人不是卑微的生物所能抵抗的！[0m\n",
		"[1m蛇人巫医说道: 你们已经被包围了，放下武器投降吧。[0m\n",
		"[1m蛇人巫医说道: 同伴们，需要治疗自己要说喔？[0m\n"
	}) );

	wield_weapon( "/d/noden/house/obj/mace" );
//	equip_armor( "/d/noden/drow/arm/a10" );
//	equip_armor( "/d/noden/drow/arm/a14" );
        equip_armor( "/d/noden/drow/arm/ring" );
        equip_armor("/obj/bandages");
        equip_armor("/obj/bandages");
        equip_armor("/obj/bandages");
        equip_armor("/obj/bandages");
        equip_armor("/obj/bandages");
}
void relay_message(string class, string str)
{
        int i,hitp,hp1,hp2;
        string name,direction,tmp;
        object victim,env,*who,bandage,target;
        mixed bandaged,bleed;
        ::relay_message(class,str);
        
        
        if( !str || str == "" ) return;
        if( sscanf(str,"%s(%s)走了过来。", tmp,name)==2 ) {
        name = lower_case(name);
        victim = present(name, environment(this_object()));
        if( !victim || victim->query("npc") || victim->query("no_attack")) return ;
        
        if( victim->query_level() > 5 && !victim->query("ghost") && victim->query("alignment") >100 ) {  
        
        if( !pointerp(attackers) || member_array(victim, attackers)==-1 ) {
        
        tell_object(victim,query("c_name")+"叫道 : 通通去死吧，同时不怀好意的往你这里冲过来....\n");
         kill_ob(victim);
         } } }
        
         if( sscanf(str,"%s(%s)说道: 敌人已经逃走了，快来帮我治疗吧.....",tmp,name)==2) 
         {
         if ( query_attacker() ) return ; 
         if ( !target = present(name,environment(this_object()) )) return ;
         if ( !target->query("chi_yu_group") ) return ;

         if ( bleed = query("conditions/bleeding") ) {
         if ( query_temp("clotted") == 0) {
         
         tell_room(environment(this_object()),set_color(
               "\n蛇人巫医趁著战斗告一段落，很快的对自己的伤口进行止血。\n\n"
               ,"HIY",this_object()),this_object());
         
         (CONDITION_PREFIX + "bleeding")->remove_effect(this_object());
         call_out( "remove_clotted", 45, target );
         }}
         
        if ( this_object()->query("hit_points") < this_object()->query("max_hp")/2 ) {
        if (!bandaged = query("conditions/bandaged")) {
         tell_room(environment(this_object()),set_color(
                  "\n蛇人巫医从怀中掏出一些药膏，很快的贴在自己的伤口上。\n\n"
                  ,"HIY",this_object()),this_object());
         
         HERB_APPLY->apply_effect(this_object(), 8, 5, 30);
         command("bandage shaman");
         }}
         
    if ( this_object()->query("hit_points") < this_object()->query("max_hp")/3) {
    if (!this_object()->query_temp("aided") || this_object()->query_temp("aided")==0) {
       tell_room(environment(this_object()),set_color(
          "\n蛇人巫医趁著战斗告一段落，很快的对自己的伤口"
          "进行急救。\n\n","HIY",this_object()),this_object());
         
         
         this_object()->receive_healing(65+random(30));
         this_object()->set_temp("aided",1);
         call_out("can_aid_again",180,this_object());
         }
         }
         if ( bleed = target->query("conditions/bleeding") ) {
         if ( target->query_temp("clotted")==0) {
         if( 50 + random(50) > bleed[1] * bleed[2] ) {
         (CONDITION_PREFIX + "bleeding")->remove_effect(target);
         } else {
         bleed[2] /= 2;
         target->set( "conditions/bleeding", bleed );
         }
         tell_room(environment(this_object()),set_color(
         "\n蛇人巫医趁著战斗告一段落，很快的对"+target->query("c_name")+
         "进行止血。\n\n","HIY",target),target);
         target->set_temp("clotted", 1 );
         call_out( "remove_clotted", 45, target );
         }
         else command("say "+target->query("c_name")+"，你的伤口已经被止血处理过了...");
}          
          hitp = target->query("hit_points");
          hp1 = target->query("max_hp")/2;
          hp2 = target->query("max_hp")/4;
     
     if (hitp < hp2 ) {
          
             if (target->query_temp("aided")==0) {
             target->receive_healing(60+random(25));
             target->set_temp("aided",1);
             call_out("can_aid_again",180,target);
             tell_room(environment(this_object()),set_color(
             "\n蛇人巫医趁著战斗告一段落，很快的对"+target->query("c_name")+
             "进行急救。\n\n","HIY",target),target);
              }
             else command("say "+target->query("c_name")+"，你已经被急救过了..."); 
              }
         
          if (hitp < hp1)  {
        
          if (!bandaged = target->query("conditions/bandaged")) {
         
          tell_room(environment(this_object()),set_color(
          "\n蛇人巫医从怀中掏出一些药膏，很快的抹在"+target->query("c_name")+
          "伤口上。\n\n","HIY",target),target);
          HERB_APPLY->apply_effect(target, 8, 5, 30);
          command("bandage "+target->query("name"));         
          return ;
          }
          }
}
}
int my_tactic()
{
	object *people;

	if( random(12)<2 ) {
        tell_room( environment(this_object()), 
	     "蛇人巫医口中念道: Grignar-substun exnAr quinolenee...\n"
	     "[32m\n一团暗绿色的光气从四面汇集，并且笼罩著在场的所有人，然後消失。[0m\n\n",
			this_object() );
		people = all_inventory(environment());
		people->heal_chi(30);
		return 1;
	} else return 0;
}

