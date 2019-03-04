#include <mudlib.h>
#include <daemons.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
    set_name("Canteen", "�ԹԺ�");
    set_short( "�ԹԺ�" );
    set_long(@LONG
����������ӱ�ֿɰ���Сˮ���������������װˮŶ��
LONG
                );
    set("weight", 3 );
    set("times",10);
    set("filled",0);
    set("value",({50,"silver"}) );
}

void init()
{
    add_action( "fill_water", "fill" );
    add_action( "drink_water", "drink" );
}

int fill_water(string arg)
{
    object env;
    int hour;
    
    sscanf(WEATHER_D->query_game_time(),"%d",hour);    
    if( !arg || arg!="canteen" )
         return notify_fail("��ʲ��װˮ��\n");

    env = environment(this_object());
    if( living(env) ) env = environment(env);

    if( this_object()->query("filled") >= 3){
      this_object()->add("filled",1);
      this_object()->set_name("Broken Canteen","�Ƶ��ĹԹԺ�");
      this_object()->set_short("�Ƶ��ĹԹԺ�");
      this_object()->set_long("����ԹԺ��Ѿ��Ƶ��ˣ���Ҳ�޷�װˮ�ˣ�\n");
      write("����������ԹԺ���װˮ���������Ѿ��Ƶ��ˣ�\n");
      this_player()->delete_temp("get_canteen");
      this_object()->set("useless");
      return 1;
      }
    if( (int)this_object()->query("times") == 0){
       write("�Ѿ�װ��ˮ����!!\n");  
       return 1;
       }
    if( (string)env->query("short")=="�����Ȫ" ||
    	(string)env->query("short")=="Сˮ��" ||
    	(string)env->query("short")=="ǧ��¥ǰͥ" ){
               if( hour >= 18 || hour <= 6 ){
            write("���ڹԹԺ���װ�����徻��Ȫˮ��\n");
            tell_room(environment(this_player()),
              this_player()->query("c_name")+"�ͳ��ԹԺ���װˮ��\n"
              ,this_player() );
            this_object()->set("times",0);
	    this_object()->add("filled",1);
	    return 1;
	}
	else {
	  write("������ֵÿ�յ�Ǭ���ڣ�û��ˮ����װ���ء�������\n");
	 tell_room( environment(this_player()),
	  this_player()->query("c_name")+"̾�˿��������ͳ��ĺ������ػ��С�\n"
	  ,this_player() );
	  return 1;
	    }
	 } 
	write("��װ�����ˮ��ʲ���ã����ֲ�Ǭ����װ����Һ���\n");
	return 1;
}

int drink_water(string arg)
{

    if( !arg || arg!="canteen" )
        return notify_fail("�����ʲ�᣿\n");
    
    if( this_object()->query("filled") >= 4 )
        return notify_fail("�ԹԺ��Ѿ����ˣ�������ʹ����...:P\n");    
    
    if( this_object()->query("times") >= 10 )
	return notify_fail("�ԹԺ��ǿյġ�\n");
    if( (int)this_player()->query("wealth/silver") <= 100){
        write("���Ѿ����Ʋ��ˣ�����������ݳ޵�ʥˮ����\n");
        return 1;
        }
/*        
    if( this_object()->query("times") >= 9 ){
      write("���ͳ��ԹԺ�����һ�ں�ʣ�µ�ˮ�⣬���......\n");
      this_object()->add( "times",1 );
      WEAK->apply_effect( this_player(),5,10 );
      return 1;
      }
 */     
    write("����ڵĺ���һ��ˮ������ö��ˣ����Ǻɰ���������ˣ�����Ǵ����!\n");
    tell_room(environment(this_player()),
       this_player()->query("c_name")+"�ó��ԹԺ�����������Ƶ��ͺ�....\n"
       ,this_player() );
        this_object()->add( "times",1 );	
    
       this_player()->add("medication_resistance",-20);
       this_player()->add("wealth/silver",-50);
      if( (int)this_player()->query("medication_resistance") < 0)
          this_player()->set("medication_resistance",0 );
       return 1;
}    
