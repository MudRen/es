#include <mudlib.h>

inherit CONTAINER;

void create()
{
        ::create();
        set_name("Paper box", "��ֽ��");
        set("id",({ "box"}));
        set_short("��ֽ��");
        set_c_open_long(@LONG
����ר�����������վݵ���Դ�����䣬����Ҫ�л������
�𽫷��վ���ƷͶ��(put)��        
LONG
        );
        set( "weight", 20);
        set( "weight_apply", 10 );
        set( "max_load", 20000);
        set( "prevent_get",1 );
        set( "prevent_put_money", 1);
}

void init()
{
    add_action("do_put","put");
}

int do_put(string arg)
{
    string *name,id;
    object *obj;
    int i,j;
    
    obj=all_inventory(this_player());
    
    i=sizeof(obj);
    if ( arg !="bill in box" || arg != "bill into box"|| !arg )
    {
    while(i--)
    {
       name=obj[i]->query( "id" );
       j=sizeof(name);
       
       while(j--)
       {    id=name[j];
       if ( id+" in box" == arg || id+" into box"==arg );
       {
          obj[i]->remove();
          write("���㲻Ҫ����˵����! û��!");
          tell_room(environment(this_player()), this_player()->query("c_name")+"��"+name+"��û����!",this_player());
          return 1 ;
        }
        }
     }
     }
       
     else 
     {
       
        if ( arg == "bill in box"|| arg == "bill into box" )
       
        {
           return 0;
        } 
       
        else
        {
          write("��Ҫ��ʲ��!?");
          return 1;
        }
       } 
}               