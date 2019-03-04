#include <mudlib.h>
#define MAXHEAL 300
#define NAME(x) (string)x->query("name")
#define LEADER(x) (string)x->query_temp("leader")
#define CNAME(x) (string)x->query("c_name")

inherit OBJECT;

void create()
{
        set_name("life ball", "����������");
        add("id", ({ "ball" }) );        
        set_short(set_color("����������","HIY"));
        set_long( @LONG
�ഫ����������̫�鹬�У�Ǭ���������ĵƻ�������λ�ؽ������ɣ�����
������������а�������Ṳ�߶䣬������С����ͬ����Щ�ؽ������˴��Ҳ
û�뵽����һ��Ǭ�������Ȼ��ͳ�ç������ⶾ�
LONG
        );
        set( "light",3); 
        set( "times_left",5);
        set( "unit", "��" );
        set( "weight", 10 );
}

void init()
{
  add_action("do_heal_all", "use_lifeball");
}

int who_in_party(object obj, string me)
{
     if( !living(obj) ) return 0;
     if( LEADER(obj)!= me ) return 0;
     return 1;
}

int do_heal_all()
{
    int i, times;
    object *part, me;
    
    me = this_player();
    if (this_object()->query("times_left")<1) {
      tell_object(me,"����������Ĺ���������������������ʧ�ˡ�\n");
      this_object()->remove();   
      return 1;
    }
    tell_object(me,@LONG

������������������������......

һƬ��ɫ������Զ��Ʈ��, �Ƽʽ������, ��ס����
LONG); 
    tell_room(environment(me),sprintf(
        "\nһƬ��ɫ������Զ��Ʈ��, �Ƽʽ������, ��ס��%s...\n",me->query("c_name")),me);
    if (!LEADER(me)||LEADER(me)!=NAME(me)) {
      tell_object(me,
        set_color("�����������ˬ, ������һ�������죡\n","HIB"));
      this_player()->receive_healing(MAXHEAL);    
      this_object()->add("times_left",-1);        
      return 1;
    }
    part=filter_array(all_inventory(environment(this_player())),
                       "who_in_party",this_object(),NAME(this_player()));
    i=sizeof(part);
    while(i--) {
      tell_object(part[i],
        set_color("�����������ˬ, ������һ�������죡\n","HIB"));    
      part[i]->receive_healing(MAXHEAL);
    } 
    this_object()->add("times_left",-1);                  
    return 1;
}
