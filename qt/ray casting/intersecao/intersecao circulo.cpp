Point p1 ,p2,p3;
            p1 = Point{1,0,0};
            p2 = Point{0,1,0};
            p3 = Point{0,0,1};
            Vec3 v1,v2;
            v1 = p3-p1;
            v2 = p2-p1;

            Point l0 = ray.o;
            Point p0 = p1;
            Vec3 l = ray.d;
            l.normalize();
            Point p;
            Vec3 n = Cross(v1,v2);
            n.normalize();

            float t;
            float raioEsfera = 1;
            float denom = Dot(n, l);
            if (denom > 1e-6) {
                Vec3 p0l0 = p0 - l0;
                t = Dot(p0l0, n) / denom;
                if(t>0){
                    image.setPixel( linhaPixel, colunaPixel, qRgb( 255, 0, 0) );
                    Vec3 p = l0 + l * t;
                    Vec3 v = p - p0;
                    float d2 = Dot(v, v);
                    if(d2 <= raioEsfera*raioEsfera){
                        image.setPixel( linhaPixel, colunaPixel, qRgb(0, 0, 255) );
                    }
                }
            }