#include <mudlib.h>
#include <daemons.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
    set_name("Canteen", "乖乖壶");
    set_short( "乖乖壶" );
    set_long(@LONG
这是造型新颖又可爱的小水壶，你可以用它来装水哦！
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
         return notify_fail("用什麽装水？\n");

    env = environment(this_object());
    if( living(env) ) env = environment(env);

    if( this_object()->query("filled") >= 3){
      this_object()->add("filled",1);
      this_object()->set_name("Broken Canteen","破掉的乖乖壶");
      this_object()->set_short("破掉的乖乖壶");
      this_object()->set_long("这个乖乖壶已经破掉了，再也无法装水了！\n");
      write("你想用这个乖乖壶来装水，可是它已经破掉了！\n");
      this_player()->delete_temp("get_canteen");
      this_object()->set("useless");
      return 1;
      }
    if( (int)this_object()->query("times") == 0){
       write("已经装满水了啦!!\n");  
       return 1;
       }
    if( (string)env->query("short")=="香津美泉" ||
    	(string)env->query("short")=="小水池" ||
    	(string)env->query("short")=="千川楼前庭" ){
               if( hour >= 18 || hour <= 6 ){
            write("你在乖乖壶中装满了清净的泉水。\n");
            tell_room(environment(this_player()),
              this_player()->query("c_name")+"掏出乖乖壶来装水。\n"
              ,this_player() );
            this_object()->set("times",0);
	    this_object()->add("filled",1);
	    return 1;
	}
	else {
	  write("现在正值每日的乾枯期，没有水可以装，呜～～～！\n");
	 tell_room( environment(this_player()),
	  this_player()->query("c_name")+"叹了口气，把掏出的壶又塞回怀中。\n"
	  ,this_player() );
	  return 1;
	    }
	 } 
	write("你装这里的水有什麽用？？又不乾净，装了你敢喝吗？\n");
	return 1;
}

int drink_water(string arg)
{

    if( !arg || arg!="canteen" )
        return notify_fail("你想喝什麽？\n");
    
    if( this_object()->query("filled") >= 4 )
        return notify_fail("乖乖壶已经破了，不能再使用了...:P\n");    
    
    if( this_object()->query("times") >= 10 )
	return notify_fail("乖乖壶是空的。\n");
    if( (int)this_player()->query("wealth/silver") <= 100){
        write("你已经快破产了，还想喝这种奢侈的圣水啊？\n");
        return 1;
        }
/*        
    if( this_object()->query("times") >= 9 ){
      write("你掏出乖乖壶，想一口喝剩下的水光，结果......\n");
      this_object()->add( "times",1 );
      WEAK->apply_effect( this_player(),5,10 );
      return 1;
      }
 */     
    write("你大大口的喝了一口水，精神好多了，可是荷包好像变轻了，大概是错觉吧!\n");
    tell_room(environment(this_player()),
       this_player()->query("c_name")+"拿出乖乖壶来，像灌蟋蟀似的猛喝....\n"
       ,this_player() );
        this_object()->add( "times",1 );	
    
       this_player()->add("medication_resistance",-20);
       this_player()->add("wealth/silver",-50);
      if( (int)this_player()->query("medication_resistance") < 0)
          this_player()->set("medication_resistance",0 );
       return 1;
}    
