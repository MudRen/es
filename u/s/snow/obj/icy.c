inherit WEAPON;

void create()
{
    set_name( "icy","冰魄" );
    set_short( "冰魄" );
    set_long(@C_LONG
这是飘雪仙姬心爱的玩具，乍看只是一枚万年寒冰，可一旦遇上危险，
仙姬就会把它幻化成强力的攻击武器。
C_LONG
            );
    set("unit","枚");
    set("weapon_class",50);
    set("type","longblade");
    set("max_damage",5);
    set("min_damage",0);
    set("weight",1);
    set("prevent_drop",1);
    set("value",({1,"silver"}) );
    set( "hit_func", "weapon_hit" );
    set("wield_func","daemon_wield");
    set("unwield_func","daemon_unwield");
}

void daemon_wield()
{
    if( (string)this_player()->query("name")=="snow") {
    set("prevent_drop",1);
    set("min_damage",30);
    set("max_damage",100);
    set("extra_look","@@color");
    tell_object( this_player(),set_color(
       "\n寒光一闪，『冰魄寒光剑』已出现在你手上．\n\n"
       ,"HIW") );
    tell_room( environment(this_player()),set_color(
       "\n"+"突然卷起一阵寒风，"+this_player()->query("c_name")+
       "手中已多了一把寒光闪闪的冰剑．\n\n"
       ,"HIW"),this_player() );
    set_name("icy sword","冰魄寒光剑");
    add("id",({"icy","sword"}) );
    set_short("冰魄寒光剑");
    return;
    }
}

void daemon_unwield()
{
        object holder ;
        if ( !holder = environment(this_object()) ) return;
    if( (int)this_object()->query("wc_damaged") ){
         tell_object( this_player(),"突然间强光一闪,你手中的冰魄寒光剑就消失不见了....\n");
         tell_room( environment(this_player()),
           "突然吹过一阵寒风"+this_player()->query("c_name")+"手中的冰魄寒光剑就消失了....\n",
           this_player() );
           this_object()->remove();
           return;
           }
    else{
    set("min_damage",0);
    set("max_damage",5);
    set("prevent_drop",1);
    delete("extra_look");
    set_name("icy","冰魄");
    set_short("冰魄");
    return ;
    }
}

int weapon_hit( object victim, int damage )
{
   object owner;
   int inte, intv, fp;

   owner = environment();
   inte = owner->query_stat("int");
   fp = owner->query("force_points");
   if (!((string)owner->query("name")=="snow")){
     tell_object( owner,
     "\n你手中的冰剑发出一阵清脆的声音：哈哈 ! 你不配做我的主人。\n\n");
     owner->receive_special_damage("energy",inte/2);
     return 0;
   }
   if (!victim) return 0;
   intv = victim->query_stat("int");
   if( random(inte*3)>(intv*2) && fp >2 ) {
       tell_object( owner,
       "\n你将一阵内力贯输於冰魄寒光剑, 剑突然发出一阵寒气向"+victim->query("c_name"
)+"射去\n\n" );
       tell_object( victim, "\n" +
          owner->query("c_name") + "的寒光剑突然发出一阵寒气向你袭来!\n\n" );
       tell_room( environment(owner),
     "\n" +
         owner->query("c_name") + "的冰剑突然向" + victim->query("c_name") + "射
出一阵寒气!\n\n"
         , ({ victim, owner }) );
       victim->receive_damage(1000);
       victim->receive_special_damage( "energy", inte/2 );
          owner->add( "force_points", -3 );
          return inte/2;
        }
}



string color()
{
    return set_color("$N的右手中握著一柄万年冰魄形成的白色长剑...\n","hiw");
}
