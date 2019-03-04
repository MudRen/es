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
        set_name( "spell", "�۽���" );
        add( "id", ({ "spell" }) );
        set_short( "�۽���" );
        set_long(@C_LONG
�۽��������������þ������������( concentrate longsword or shortsword )
��һ�ѱ��С�
C_LONG        
        );
        set("unit","��");
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
          return notify_fail( "��,���Ɀ������Ҫ��ʲ�����Ľ���??\n");
      
      if ( query("used") )
          return notify_fail( "\n����Ҫ��Ϣһ�²������۾���........ \n");
      
      if ( MP(me) < COST_MP )       
          return notify_fail( "\n��û�������㹻�ľ�����.......\n"); 
      
      if ( FP(me) < COST_FP )
          return notify_fail( "\n��û�������㹻������.....\n");
      
      set("used",1);
      me->add( "spell_points", -COST_MP );
      me->add( "force_points", -COST_FP );
      tell_object(me,
         set_color("\n��!���Ծ������������һ�ѽ�....\n","HIW")); 
      tell_room(environment(me),
         "\n��!"+name+"�Ծ������������һ�ѽ�....\n",me);
      
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
        "\n������,���������������Ľ����ٸ����κ�������Ҫ��ʧ��........\n","HIW"));
     tell_room(environment(obj),
        "\n������,"+name+"�������������Ľ����ٸ����κ�������Ҫ��ʧ��........\n",obj);  
}
void vanish_out2()
{
     tell_object(environment(this_object()),
        "\n���������㹻�ľ����������.....\n");
     delete("used");
}
