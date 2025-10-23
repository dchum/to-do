#pragma once


namespace cui
{
    struct Size
    {
        int x, y; //< Левый верхний угол
        int width, height;
    };
    

    class Surface
    {
        protected:
            Surface( );

        public:
            virtual Size ComputeSize( int parent_width, int parent_height ) = 0;

            virtual ~Surface(){}
    };

    class FixedSurface: public Surface
    {
        private:
            int x_, y_, width_, height_;

        public:
            FixedSurface( float x, float y, int width, int height );

            Size ComputeSize( int, int ) override;
    };

    class RelativeSurface: public Surface
    {
        private:
            int x_,     y_,     width_,     height_, 
                rel_x_, rel_y_, rel_width_, rel_height_;

        public:
            RelativeSurface( float x, float y, int width, int height );

            Size ComputeSize( int parent_width, int parent_height ) override;
    };


}//namespace cui