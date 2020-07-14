#include <gazebo_test_tools/gazebo_cube_spawner.h>


int main(int argc, char** argv) {
    ros::init(argc, argv, "gazebo_cube_spawner");

    if (argc < 5)
    {
        ROS_INFO("Usage: %s <name> [x y z] [dimx dimy dimz] [is_box] [frame_id].",argv[0]);
        ROS_INFO("If cylinder will eb spawned, Usage: %s <name> [x y z] [radius height notUsed] [is_box] [frame_id].",argv[0]);
        return 0;
    }

    ros::NodeHandle node; 
    gazebo_test_tools::GazeboCubeSpawner spawner(node);

    ROS_INFO("Running spawn cube once..");

    std::string name=argv[1];
    float x=0;
    float y=0;
    float z=0;
    float dimx=0.05;
    float dimy=0.05;
    float dimz=0.05;
    int is_box=1;
    std::string frame_id="world";
    if (argc>2) x=atof(argv[2]);
    if (argc>3) y=atof(argv[3]);
    if (argc>4) z=atof(argv[4]);
    if (argc>5) dimx=atof(argv[5]);
    if (argc>6) dimy=atof(argv[6]);
    if (argc>7) dimz=atof(argv[7]);
    if (argc>8) is_box=atoi(argv[8]); 
    if (argc>9) frame_id=argv[9];
    float mass=0.05;
    if(is_box){
        spawner.spawnCube(name,frame_id,x,y,z,0,0,0,1,dimx,dimy,dimz,mass);
    }
    else{
        spawner.spawnCylinder(name,frame_id,x,y,z,0,0,0,1,dimx,dimy,dimz,mass);
    }
    
    return 0;
}
