#include "../dony.h"

#define COST_MP 30
#define COST_FP 40
#define MP(x) (int)x->query("spell_points")
#define FP(x) (int)x->query("force_points")
 
inherit OBJECT;
string name;
void create()
{
        seteuid(getuid());
#include <compress_obj.h>
        set_name( "spell", "聚剑术" );
        add( "id", ({ "spell" }) );
        set_short( "聚剑术" );
        set_long(@C_LONG
聚剑术可以让你运用精神和内力凝聚( concentrate longsword or shortsword )
出一把宝刃。
C_LONG        
        );
        set("unit","个");
        set("weight", 1 );
        set("prevent_drop", 1);
        set("prevent_get",1);
}

int query_auto_load()
{
        return 1;
}

void init()
{
   add_action( "cast_spell", "concentrate" );
}   
   
int cast_spell(string str)
{
      object me,ob1;
      
      me=this_player();     
      name=me->query("c_name");
     
      if( str!="shortsword"&&str!="longsword" )
          return notify_fail( "咦,你这笨蛋到底要聚什麽样的剑啦??\n");
      
      if ( query("used") )
          return notify_fail( "\n你需要休息一下才能凝聚精神........ \n");
      
      if ( MP(me) < COST_MP )       
          return notify_fail( "\n你没有凝聚足够的精神力.......\n"); 
      
      if ( FP(me) < COST_FP )
          return notify_fail( "\n你没有凝聚足够的内力.....\n");
      
      set("used",1);
      me->add( "spell_points", -COST_MP );
      me->add( "force_points", -COST_FP );
      tell_object(me,
         set_color("\n吓!你以精神和内力化出一把剑....\n","HIW")); 
      tell_room(environment(me),
         "\n吓!"+name+"以精神和内力化出一把剑....\n",me);
      
      seteuid( getuid ( this_object() ) );
      if (str=="longsword"){
         ob1=new(DWEAPON"spirit_sword");
         ob1->move( me );
         call_out( "vanish_out1", 3600, me );
         call_out( "vanish_out2", 3620);
      } else {
          ob1=new(DWEAPON"spirit_shortsword");
          ob1->move( me );
          call_out( "vanish_out1", 3600, me );
          call_out( "vanish_out2", 3620);
     }   
      return 1;
}
void vanish_out1(object obj)
{
     tell_object(environment(this_object()),set_color(
        "\n渐渐地,你以灵气化出来的剑不再附有任何灵气而要消失了........\n","HIW"));
     tell_room(environment(obj),
        "\n渐渐地,"+name+"以灵气化出来的剑不再附有任何灵气而要消失了........\n",obj);  
}
void vanish_out2()
{
     tell_object(environment(this_object()),
        "\n你又凝聚足够的精神和内力了.....\n");
     delete("used");
}
