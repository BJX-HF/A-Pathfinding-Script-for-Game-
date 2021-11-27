scr_mbx=argument0;  //目标x
scr_mby=argument1;  //目标y

scr_acx=x;
scr_acy=y;

scr_nx=0;  //
scr_ny=0;  //

scr_lit=30;

scr_openglist[0,0]=-1;  //父对象点坐标  0，1  本体坐标 2，3  F值 4  是否被使用5 使用了 1
scr_op=0;  //开启列表计数
scr_zop=1; //判定在不在开启列表中

scr_closelist[0,0]=0;  //父对象点坐标  0，1  本体坐标 2，3  F值 4
scr_cls=0;  //关闭列表计数
scr_cn=0;   //
scr_CF=90000;
//scr_cm=0;

scr_i=0;
//初始化 两个列表
for(scr_i=0;scr_i<3600;scr_i++)
{
    scr_closelist[scr_i,0]=-1;
    scr_openglist[scr_i,0]=-1;
    scr_closelist[scr_i,1]=-1;
    scr_openglist[scr_i,1]=-1;
    scr_closelist[scr_i,2]=-1;
    scr_openglist[scr_i,2]=-1;
    scr_closelist[scr_i,3]=-1;
    scr_openglist[scr_i,3]=-1;
    scr_closelist[scr_i,4]=-1;
    scr_openglist[scr_i,4]=-1;
    //scr_closelist[scr_i,0]=-1;
    scr_openglist[scr_i,5]=0;
}



scr_F=0;


scr_i=0;  //判定最终点是否找到
scr_n=0;
//scr_m=0;

scr_closelist[0,0]=-1;scr_closelist[0,1]=-1;scr_closelist[0,2]=x;scr_closelist[0,3]=y;scr_closelist[0,4]=-1;  //起始点计入关闭列表
scr_openglist[0,0]=-1;scr_openglist[0,1]=-1;scr_openglist[0,2]=x;scr_openglist[0,3]=y;scr_openglist[0,4]=-1;  scr_openglist[0,5]=1;//给开启列表一个初始值计入开启列表



//最大的循环  
{
while(scr_i=0)
{ 
    scr_nx=scr_acx-scr_lit;
    scr_ny=scr_acy;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if scr_nx>0
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++;               
            }
            }
            
        }
    }
    scr_nx=scr_acx+scr_lit;
    scr_ny=scr_acy;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if scr_nx<2000
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++;               
            }
            }
            
        }
    }
    scr_nx=scr_acx;
    scr_ny=scr_acy-scr_lit;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if scr_ny>0
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++;               
            }
            }
            
        }
    }
    scr_nx=scr_acx;
    scr_ny=scr_acy+scr_lit;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if scr_ny<1600
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++;               
            }
            }
            
        }
    }  
    scr_nx=scr_acx+scr_lit;
    scr_ny=scr_acy-scr_lit;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if (scr_ny>0)&&(scr_nx<2000)
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++;
            }
            }
            
        }
    }
    scr_nx=scr_acx-scr_lit;
    scr_ny=scr_acy-scr_lit;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if (scr_ny>0)&&(scr_nx>0)
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++; 
            }
            }
            
        }
    }
    scr_nx=scr_acx+scr_lit;
    scr_ny=scr_acy+scr_lit;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if (scr_ny<1600)&&(scr_nx<2000)
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++;
            }
            }
            
        }
    }
    scr_nx=scr_acx-scr_lit;
    scr_ny=scr_acy+scr_lit;
    //判断预定点是否是终点
    if (scr_nx==scr_mbx)&&(scr_ny==scr_mby)
    {
        scr_i=1;
        scr_cls++;
        scr_closelist[scr_cls,0]=scr_acx;
        scr_closelist[scr_cls,1]=scr_acy;
        scr_closelist[scr_cls,2]=scr_nx;
        scr_closelist[scr_cls,3]=scr_ny;
        break;
    }
    //判定预计点是否到了地图外
    if (scr_ny<1600)&&(scr_nx>0)
    {
        //判定是否是不可行点
        if !collision_rectangle(scr_nx-20,scr_ny-20,scr_nx+20,scr_ny+20,obj_solid,0,0)
        {
            //判定在不在开启列表中
            scr_n=0;
            {
            while(scr_n<=scr_op)
            {
                if (scr_nx==scr_openglist[scr_n,2])
                {
                    if (scr_ny==scr_openglist[scr_n,3]) 
                    {
                        scr_zop=1;
                        scr_n=scr_op;
                        scr_n+=2;
                    }
                    else
                    {
                        scr_zop=0;
                    }
                }
                else
                {
                    scr_zop=0;
                }
                //不在 并计入开启列表
                if (scr_zop==0)&&(scr_n==scr_op)
                {   
                    scr_op++;                 
                    scr_openglist[scr_op,0]=scr_acx;
                    scr_openglist[scr_op,1]=scr_acy;
                    scr_openglist[scr_op,2]=scr_nx;
                    scr_openglist[scr_op,3]=scr_ny;
                    scr_F=sqrt((scr_nx-x)*(scr_nx-x)+(scr_ny-y)*(scr_ny-y))+abs(scr_mbx-scr_nx)+abs(scr_mby-scr_ny);
                    scr_openglist[scr_op,4]=scr_F;
                    scr_zop=1;
                    scr_n+=2;
                }
                scr_n++;
            }
            }
            
        }
    }
    //找到最小的F值 并将该点加入关闭列表 并记录关闭状态 然后改变 acx的值和acy的值 并重新开始找下一个记录点
    {
        for(scr_cn=0;scr_cn<=scr_op;scr_cn++)
        {
        //找到最小的可用的F值
            if scr_openglist[scr_cn,5]==0
            {
                if scr_CF>scr_openglist[scr_cn,4]
                {
                    scr_CF=scr_openglist[scr_cn,4];
                }                
            }
        }
            //完成循环后，确认最小F值后 加入关闭列表
        for(scr_cn=0;scr_cn<=scr_op;scr_cn++)
        {

                        if scr_openglist[scr_cn,4]==scr_CF
                        {
                            if scr_openglist[scr_cn,5]==0
                            {
                            scr_cls++;
                            scr_closelist[scr_cls,0]=scr_openglist[scr_cn,0];
                            scr_closelist[scr_cls,1]=scr_openglist[scr_cn,1];
                            scr_closelist[scr_cls,2]=scr_openglist[scr_cn,2];
                            scr_closelist[scr_cls,3]=scr_openglist[scr_cn,3];
                            scr_closelist[scr_cls,4]=scr_openglist[scr_cn,4];
                            scr_openglist[scr_cn,5]=1;                            
                            scr_acx=scr_openglist[scr_cn,2];
                            scr_acy=scr_openglist[scr_cn,3];
                            if (scr_acx==scr_mbx)&&(scr_acy==scr_mby)
                            {
                                scr_i=1;
                            }
                            scr_cn=scr_op+1;
                            }
                        }

        }
        scr_CF=90000;
    }   
    
}
}



//移动阶段的变量
//movearry[0,0]=0;  //最终的移动数据
scr_move_i=scr_cls;   //循环变量
scr_move_n=0;
scr_jieshu=0;

scr_fujishu=50;

//move_time=0;  
scr_move_ax=scr_mbx;  
scr_move_ay=scr_mby;  


//将closelist的数据正确加载到移动数组中
//closelist中的从最后一个数据开始反找每个数据的父对象直到找到closelist的第一个数据
{
    while(scr_jieshu=0)
    {
        //将当前closelist的坐标记录到movearry数组中
        ds_grid_set(global.movearry,scr_move_n,0,scr_closelist[scr_move_i,2]);
        //movearry[scr_move_n,0]=scr_closelist[scr_move_i,2];
        ds_grid_set(global.movearry,scr_move_n,1,scr_closelist[scr_move_i,3]);
        //movearry[scr_move_n,1]=scr_closelist[scr_move_i,3];
        scr_move_n++;
        //记录当前的父对象的坐标
        scr_move_ax=scr_closelist[scr_move_i,0];
        scr_move_ay=scr_closelist[scr_move_i,1];
        //寻找当前对象的父对象所在的位置        
        {
            scr_fujishu=scr_cls;
            while(scr_fujishu>=0)
            {
                if scr_closelist[scr_fujishu,2]==scr_move_ax
                {
                    if scr_closelist[scr_fujishu,3]==scr_move_ay
                    {
                        scr_move_i=scr_fujishu;
                        if scr_closelist[scr_move_i,4]==-1
                        {
                            ds_grid_set(global.movearry,scr_move_n,0,scr_closelist[scr_move_i,2]);
                            ds_grid_set(global.movearry,scr_move_n,1,scr_closelist[scr_move_i,3]);
                            //movearry[scr_move_n,0]=scr_closelist[scr_move_i,2];
                            //movearry[scr_move_n,1]=scr_closelist[scr_move_i,3];
                            scr_jieshu=1;
                        }
                        scr_fujishu=-1;                        
                    }                    
                }
                scr_fujishu--;
            }
        }
    }
}

return scr_move_n;