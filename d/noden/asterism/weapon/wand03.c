#include "../asterism.h"

inherit WEAPON;

void create()
{
    set_name("Wand of Ultimate","永恒之杖");
    add("id",({"wand","ultimate wand"}) );
    set_short("永生之杖");
    set_long(@DESC
这把魔杖的杖身是由神密的米苏理金属打造而成,它的前端部份镶著一
颗水晶球,自古相传这颗水晶球中藏著永恒生命的秘密.矮人的傲人矿物,
半身人的工艺技术,再加上地精的神圣魔力,使这把法杖成为魔法师心中
梦寐以求的武器.
DESC
);
    set("unit","把");
    set("weapon_class",40);
    set("type","wand");
    set("min_damage",18) ;
    set("max_damage",37);
    set("used_times",0);
    set("weight",90);
    set("value",({450,"gold"}));
    set("hit_func","wand_damage");
    set("special_damage",55);
    set("special_msg"," grow a bright,coverd");
    set("special_c_msg","前端的水晶球发出一阵强光,包围住");
    set("no_sale",1);

}

int wand_damage(object victim,int damage)
{
    object holder;
    int my_kar,vic_kar,dam,my_sp,my_wand,wc,damaged,ran,times;

    string c_msg,msg;
    
    if( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) 
        return 0;
	
    
    	
    my_kar  = (int)holder->query_stat("kar");
    vic_kar =(int)victim->query_stat("kar");
    my_sp   =(int)holder->query("spell_points") ; 
    my_wand =(int)holder->query_skill("wand") ;
    wc      = (int)this_object()->query("weapon_class") ;
    damaged =(int)this_object()->query("damaged") ;          
    times   = query("used_times");           
    ran     = random(35-my_kar) ;
    
    if( (int)holder->query("npc")==1 ) ran = 1 ;
        
    if( 35-my_kar <0) ran = 1 ;
        
    if(!(dam = (int)this_object()->query("special_damage")) ) 
            return 0 ;
                    
    if(!damaged && random(my_wand*2)<ran && times>8 && (int)holder->query("npc")!=1)
        { 
           write(
                "你的水晶球被敌人敲到,破掉了.\n\n"
                );
           tell_room( environment(holder),
                sprintf("\n%s手上%s前端的水晶球乓的一声,破了.\n\n",
		holder->query("c_name"),query("c_name")),
                holder ) ;     
                        
           this_object()->add("short"," (受损)") ;    
           this_object()->set("weapon_class",3*wc/5) ;
           this_object()->set("min_damage",20) ;
           this_object()->set("max_damage",30) ; 
           this_object()->set("damaged",1);
           return 0 ;
         }        
                         
    if( random(vic_kar)>random(my_kar/4) )  return 0;
    if(	(int)holder->query("npc")==1 && random(3) < 2 ) return 0;

    c_msg = (string)query("special_c_msg");
    
    if( !c_msg ) return 0;

    if(my_sp<30)
        { 
          tell_object(holder ,
	        "你的法力不足以聚集地精的神秘力量.\n"
	        );
          return 0 ;
         }  
		       
    if(!(!damaged))
        {  tell_object(holder ,
                "你见到破裂的水晶球闪过一阵异样的光芒,然後立刻消失.\n") ;
           tell_room( environment(holder), 
                sprintf("\n%s手上%s前端破掉的水晶球发出一阵异样的光芒,然後立刻消失\n",
		holder->query("c_name"),query("c_name"))
                    ,holder ) ;     
                     
           holder->set("spell_points",my_sp-10) ;                       
           return 0 ;
            }    
                        
    holder->set("spell_points",my_sp-30) ;
    victim->receive_damage( dam );
    victim->set("last_attacker", holder );                       
    this_object()->set("used_times",times+1);
                
    tell_object( holder, 
           sprintf("你的%s%s%s\n" ,
	query("c_name"),c_msg,victim->query("c_name")));

    tell_room( environment(holder), 
	   sprintf("%s的%s%s%s\n",
		holder->query("c_name"),query("c_name"),c_msg,victim->query("c_name")),
            ({holder,victim}));

    tell_object( victim,
           sprintf("%s的%s%s你.\n" ,
	holder->query("c_name"),query("c_name"),c_msg)
               	); 	        
	 
    return dam; 
     
}	

