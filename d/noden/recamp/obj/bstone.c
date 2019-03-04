#include <mudlib.h>
inherit OBJECT;
int weted;

string query_c_long()
{
   if ( weted )
  	return  "���մ��ˮ��ʯͷ�ƺ���Ҫ�ܵ��ˣ������Ͽ����ŪǬ(dry)��\n"
        	"��ɵ�׼����ȥ�����ŵ�һ�ٳ����ֻ�ý��·�����!!��\n";
	else
	return  "�����ɫʯͷ��������ġ�����ģ���һ��ʯͷ��̫һ��������\n"
		"�ƺ�д�������� w?t���м���ֱ�һ���� �� ����ס�����������\n";
}

void create()
{
	set_name("black stone", "��ɫʯͷ");
	add( "id", ({ "blackstone","stone" }) );
	set_short( "��ɫʯͷ" );
	set("long","@@query_c_long");
	set( "weight", 3 );
	weted = 0;
}

int query_weted() { return weted; }

void init()
{
	add_action( "wet_stone", "wet" );
	add_action( "dry_stone", "dry" );
	add_action( "apply_wall", "apply" );
}

int wet_stone(string arg)
{
   object env;

   if( !arg || arg!="blackstone" && arg != "stone" )
     return notify_fail("��ʲ��Ūʪ��\n");
   if ( weted )
     return notify_fail("��ɫʯͷ�Ѿ�Ūʪ��,�ƺ���������Ϳī(apply)!!��\n");

	env = environment(this_object());
	if( living(env) ) env = environment(env);
	if( !env->query("water_source") )
		return notify_fail("����û��ˮ....��\n");

	weted = 1;
	write("��Ѻ�ɫʯͷŪʪ���ƺ���������Ϳī(apply)!!��\n");
	call_out("mess_up", 200);
	return 1;
}

int dry_stone(string arg)
{
        if( !arg || arg!="blackstone" && arg != "stone" )
		return notify_fail("ŪǬʲ�᣿\n");
	if( !weted )
		return notify_fail("������? ��ɫʯͷ�Ѿ���Ǭ��ѽ!!��\n");
	weted = 0;
	write("���ſ������ǧ��޹�˵Ĺ����Ѻ�ɫʯͷŪǬ�ˡ�\n");
	return 1;
}

void mess_up()
{
	object owner;
        if (!weted) return ; 
	owner = environment(this_object());
	if( living(owner) ) {
	tell_object(owner, "��ɫʯͷ�Ѿ�Ū��������·�����ȥ�ɵð����ֻ�����ֽ������ˡ�\n");
	}
	remove();
	return;
}

int apply_wall(string str)
{
        object obj1, obj2;
   if (!weted) {
     write("�㲻�������Լ����Դ�˵���㶺����ûˮ����Ϳī�أ�\n") ;
     return 1;
   } else {
        if ( !str || str=="" || str !="wall" )
          write("����Լ�Ū��һ��������ģ�������׷����˧�����Ů� !!\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("apply")==1) 
              obj2->to_find_wall(str);
            else
              write("���ﲻ�����Ϳī�����ı�ץ����ƨ�ɣ�\n");
          }
          else return notify_fail("�����ϲ�û�й��ߡ�\n");  
        }
        return 1;
  }
}
