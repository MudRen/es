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
	set_name( "snaky shaman", "ÉßÈËÎ×Ò½" );
	add( "id", ({ "healer", "shaman" }) );
	set_short( "ÉßÈËÎ×Ò½" );
	set_long(
		"ÉßÈËÆäÊµ¿ÉÒÔËµÊÇÃ»ÓÐ½ÅµÄòáòæÈË£¬ËäÃ»ÓÐòáòæÈËÄÇ÷áÇ¿×³\n"
		"µ«ÊÇÈ´ÓÐÔ¶¸ßì¶ËûÃÇµÄÖÇ»Û¡£ÉßÈËÎ×Ò½ÄÜ¹»ÀûÓÃËüËùÑ§µÄÒ½Êõ\n"
	        "ºÍÂÌÄ§·¨ÒÔ°ïÖúÐèÒª°ïÖúµÄ¶ÓÓÑ¡£\n"
	);
	set("chi_yu_group",1);
	set( "unit", "Ãû" );
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
		"[1mÉßÈËÎ×Ò½ËµµÀ: ÄãÃÇ»¹ÊÇ·ÅÆú°É£¬Î°´óµÄò¿ÓÈ´óÈË²»ÊÇ±°Î¢µÄÉúÎïËùÄÜµÖ¿¹µÄ£¡[0m\n",
		"[1mÉßÈËÎ×Ò½ËµµÀ: ÄãÃÇÒÑ¾­±»°üÎ§ÁË£¬·ÅÏÂÎäÆ÷Í¶½µ°É¡£[0m\n",
		"[1mÉßÈËÎ×Ò½ËµµÀ: Í¬°éÃÇ£¬ÐèÒªÖÎÁÆ×Ô¼ºÒªËµà¸£¿[0m\n"
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
        if( sscanf(str,"%s(%s)×ßÁË¹ýÀ´¡£", tmp,name)==2 ) {
        name = lower_case(name);
        victim = present(name, environment(this_object()));
        if( !victim || victim->query("npc") || victim->query("no_attack")) return ;
        
        if( victim->query_level() > 5 && !victim->query("ghost") && victim->query("alignment") >100 ) {  
        
        if( !pointerp(attackers) || member_array(victim, attackers)==-1 ) {
        
        tell_object(victim,query("c_name")+"½ÐµÀ : Í¨Í¨È¥ËÀ°É£¬Í¬Ê±²»»³ºÃÒâµÄÍùÄãÕâÀï³å¹ýÀ´....\n");
         kill_ob(victim);
         } } }
        
         if( sscanf(str,"%s(%s)ËµµÀ: µÐÈËÒÑ¾­ÌÓ×ßÁË£¬¿ìÀ´°ïÎÒÖÎÁÆ°É.....",tmp,name)==2) 
         {
         if ( query_attacker() ) return ; 
         if ( !target = present(name,environment(this_object()) )) return ;
         if ( !target->query("chi_yu_group") ) return ;

         if ( bleed = query("conditions/bleeding") ) {
         if ( query_temp("clotted") == 0) {
         
         tell_room(environment(this_object()),set_color(
               "\nÉßÈËÎ×Ò½³ÃÖøÕ½¶·¸æÒ»¶ÎÂä£¬ºÜ¿ìµÄ¶Ô×Ô¼ºµÄÉË¿Ú½øÐÐÖ¹Ñª¡£\n\n"
               ,"HIY",this_object()),this_object());
         
         (CONDITION_PREFIX + "bleeding")->remove_effect(this_object());
         call_out( "remove_clotted", 45, target );
         }}
         
        if ( this_object()->query("hit_points") < this_object()->query("max_hp")/2 ) {
        if (!bandaged = query("conditions/bandaged")) {
         tell_room(environment(this_object()),set_color(
                  "\nÉßÈËÎ×Ò½´Ó»³ÖÐÌÍ³öÒ»Ð©Ò©¸à£¬ºÜ¿ìµÄÌùÔÚ×Ô¼ºµÄÉË¿ÚÉÏ¡£\n\n"
                  ,"HIY",this_object()),this_object());
         
         HERB_APPLY->apply_effect(this_object(), 8, 5, 30);
         command("bandage shaman");
         }}
         
    if ( this_object()->query("hit_points") < this_object()->query("max_hp")/3) {
    if (!this_object()->query_temp("aided") || this_object()->query_temp("aided")==0) {
       tell_room(environment(this_object()),set_color(
          "\nÉßÈËÎ×Ò½³ÃÖøÕ½¶·¸æÒ»¶ÎÂä£¬ºÜ¿ìµÄ¶Ô×Ô¼ºµÄÉË¿Ú"
          "½øÐÐ¼±¾È¡£\n\n","HIY",this_object()),this_object());
         
         
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
         "\nÉßÈËÎ×Ò½³ÃÖøÕ½¶·¸æÒ»¶ÎÂä£¬ºÜ¿ìµÄ¶Ô"+target->query("c_name")+
         "½øÐÐÖ¹Ñª¡£\n\n","HIY",target),target);
         target->set_temp("clotted", 1 );
         call_out( "remove_clotted", 45, target );
         }
         else command("say "+target->query("c_name")+"£¬ÄãµÄÉË¿ÚÒÑ¾­±»Ö¹Ñª´¦Àí¹ýÁË...");
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
             "\nÉßÈËÎ×Ò½³ÃÖøÕ½¶·¸æÒ»¶ÎÂä£¬ºÜ¿ìµÄ¶Ô"+target->query("c_name")+
             "½øÐÐ¼±¾È¡£\n\n","HIY",target),target);
              }
             else command("say "+target->query("c_name")+"£¬ÄãÒÑ¾­±»¼±¾È¹ýÁË..."); 
              }
         
          if (hitp < hp1)  {
        
          if (!bandaged = target->query("conditions/bandaged")) {
         
          tell_room(environment(this_object()),set_color(
          "\nÉßÈËÎ×Ò½´Ó»³ÖÐÌÍ³öÒ»Ð©Ò©¸à£¬ºÜ¿ìµÄÄ¨ÔÚ"+target->query("c_name")+
          "ÉË¿ÚÉÏ¡£\n\n","HIY",target),target);
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
	     "ÉßÈËÎ×Ò½¿ÚÖÐÄîµÀ: Grignar-substun exnAr quinolenee...\n"
	     "[32m\nÒ»ÍÅ°µÂÌÉ«µÄ¹âÆø´ÓËÄÃæ»ã¼¯£¬²¢ÇÒÁýÕÖÖøÔÚ³¡µÄËùÓÐÈË£¬È»ááÏûÊ§¡£[0m\n\n",
			this_object() );
		people = all_inventory(environment());
		people->heal_chi(30);
		return 1;
	} else return 0;
}

